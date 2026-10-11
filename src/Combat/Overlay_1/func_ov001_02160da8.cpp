#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

struct ScriptArgument { char data[8]; };
struct ObjectLoadCommand {
    unsigned char kind : 4;
    unsigned char group : 4;
    unsigned char action;
    short objectId;
    unsigned char field_4;
    char pad0[3];
    union { char filename[36]; int resourceId; } resource;
    int task;
    unsigned char option;
    unsigned char field_31;
    char pad1[2];
    ObjectLoadCommand* next;
};
struct ScriptState {
    #if defined(jpn)
    char pad0[0xcc]; ObjectLoadCommand* commands;
#else
    char pad0[0xd0]; ObjectLoadCommand* commands;
#endif
    char pad1[0xf8 - 0xd4]; unsigned int flags : 27; unsigned int nextObject : 5;
    char pad2[0x116 - 0xfc]; signed char selectedObject;
};
struct Obj02061bd8;
extern "C" int func_ov017_021d60f4(ScriptArgument*);
extern "C" const char* func_ov017_021d612c(ScriptArgument*);
int GetField0x397cValue(GameState*);
GameObject* GetCombatantWithFlag0x1000(GameState*, int);
int GetNibbleAt56b(void*);
int CheckField0x56bLowNibble(Obj02061bd8*);
extern SafeAllocator* data_ov001_021658b8[];
extern const char data_ov001_02165728[];
extern const char data_ov001_02165745[];
extern const char data_ov001_02165775[];
extern const char data_ov001_021657b2[];

// USA: func_ov001_02160da8
extern "C" ARM int func_ov001_02160da8(ScriptArgument* arguments, int count) {
    GameState* game = GameState::GetInstance();
    ObjectLoadCommand* command;
    ScriptState* state = (ScriptState*)func_ov017_0218b5b0()->unknown_ptr_array_371c[6];
    SafeAllocator* allocator = data_ov001_021658b8[0];
    unsigned int objectId = state->nextObject + 160;
    if (objectId > 191) return 0;
    command = (ObjectLoadCommand*)allocator->Allocate(sizeof(ObjectLoadCommand));
    command->kind = 0;
    command->group = 0;
    command->action = 0;
    command->objectId = 0;
    command->field_4 = 0;
    memset(command->resource.filename, 0, sizeof(command->resource.filename));
    command->task = -1;
    command->next = 0;
    command->option = 0;
    command->field_31 = 0;
    command->kind = (unsigned char)func_ov017_021d60f4(arguments);
    switch (command->kind) {
    case 0:
    case 1:
    case 9:
        if (count < 2) return 0;
        command->action = func_ov017_021d60f4(arguments + 1);
        if (command->kind == 1) command->objectId = GetField0x397cValue(game);
        else if (command->kind == 9) {
            command->objectId = state->selectedObject;
            if (!GetCombatantWithFlag0x100(game, command->objectId)) command->objectId = GetField0x397cValue(game);
        }
        if (command->objectId == 0) command->group = 1;
        else command->group = 2;
        break;
    case 11:
    case 12:
    case 13:
        if (count < 2) return 0;
        command->action = func_ov017_021d60f4(arguments + 1);
        command->group = 2;
        GetField0x397cValue(game);
        if (command->kind == 11) command->objectId = 3;
        else if (command->kind == 12) command->objectId = 2;
        else if (command->kind == 13) command->objectId = 1;
        if (!game->GetGameObjectByIndex(command->objectId)) {
            command->kind = 15;
            return 0;
        }
        break;
    case 10: {
        if (count < 2) return 0;
        command->action = func_ov017_021d60f4(arguments + 1);
        int group = 0;
        GameObject* member = GetCombatantWithFlag0x1000(game, 0xce);
        if (member) {
            command->objectId = 0xce;
            group = GetNibbleAt56b(member);
        } else {
            int index;
            for (index = 0; index < 4; ++index) {
                GameObject* member = GetCombatantWithFlag0x1000(game, index);
                if (member && CheckField0x56bLowNibble((Obj02061bd8*)member)) {
                    command->objectId = index;
                    group = GetNibbleAt56b(member);
                    break;
                }
            }
            if (index == 4) return 0;
        }
        command->group = (unsigned char)(group + 2);
        break;
    }
    case 2:
    case 6:
    case 7: {
        if (count < 3) return 0;
        const char* filename = func_ov017_021d612c(arguments + 1);
        if (command->kind == 6) {
            if (!strstr(filename, data_ov001_02165728)) return 0;
            const char* slash = strrchr(filename, '/');
            if (slash) filename = slash + 1;
            strcpy(command->resource.filename, filename);
        } else sprintf(command->resource.filename, data_ov001_02165745, filename);
        command->action = func_ov017_021d60f4(arguments + 2);
        command->objectId = state->nextObject + 160;
        ++state->nextObject;
        if (count > 3) command->option = func_ov017_021d60f4(arguments + 3);
        break;
    }
    case 8:
        if (count < 2) return 0;
        sprintf(command->resource.filename, data_ov001_02165775);
        command->action = func_ov017_021d60f4(arguments + 1);
        command->objectId = state->nextObject + 160;
        ++state->nextObject;
        if (count > 2) command->option = func_ov017_021d60f4(arguments + 2);
        break;
    case 3:
        if (count < 3) return 0;
        sprintf(command->resource.filename, data_ov001_021657b2, func_ov017_021d612c(arguments + 1));
        command->action = func_ov017_021d60f4(arguments + 2);
        if (count > 3) command->option = func_ov017_021d60f4(arguments + 3);
        break;
    case 4:
    case 5:
        if (count < 3) return 0;
        command->resource.resourceId = func_ov017_021d60f4(arguments + 1);
        command->action = func_ov017_021d60f4(arguments + 2);
        if (command->kind == 4) {
            command->objectId = state->nextObject + 160;
            ++state->nextObject;
        }
        break;
    default:
        return 0;
    }
    if (!state->commands) state->commands = command;
    else {
        ObjectLoadCommand* tail = state->commands;
        while (tail->next) tail = tail->next;
        tail->next = command;
    }
    return 1;
}
