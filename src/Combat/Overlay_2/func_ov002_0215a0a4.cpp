#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Container020e0310 {
    char padding[0x10];
};
struct CombatNameReference {
    char data[12];
};
struct MessageBuffer0215a0a4 {
    char text[0x860];
    char scratch[0x100];
};
struct CombatMessageMenu0215a0a4 {
    char padding_0[8];
    CombatNameReference actorReference;
    CombatNameReference targetReference;
    Container020e0310 messages;
    char padding_30[0x1bb8 - 0x30];
    int x;
    int y;
    int field_1bc0;
    char padding_1bc4[0xc];
    MessageBuffer0215a0a4* primary;
    MessageBuffer0215a0a4* backup;
    char padding_1bd8[0x1c20 - 0x1bd8];
    signed char actorId;
    signed char partyIndex;
    char padding_1c22[4];
    short command;
    short messageId;
    short field_1c2a;
    char padding_1c2c[5];
    unsigned char ready;
    char padding_1c32[0x2488 - 0x1c32];
    short detailMessage;
    unsigned char active;
};
struct CommandResult0215a0a4 {
    unsigned char type;
    char padding[5];
};
struct CombatCommand0215a0a4 {
    char padding[2];
    signed char actorId;
    unsigned char targetCount;
    signed char targetIds[4];
    CommandResult0215a0a4 results[4];
};
struct CombatEntry0215a0a4 {
    char* name;
    int field_4;
    unsigned int cost : 8;
    unsigned int padding_8 : 24;
};
struct PartyFlags0215a0a4 {
    unsigned int flags;
};
struct PartyMember0215a0a4 {
    char padding_0[0x130];
    PartyFlags0215a0a4* status;
};
struct Obj02046574 {
    CombatNameReference* actor;
    char padding_4[0xc];
    CombatNameReference* target;
};
struct StoreStruct;
struct Obj02048350;
void* GetData02153637();
void Dispatch020e3428(void*, int);
Obj02046574* GetGlobalField0x1c020421a0();
char* GetData02108e10();
CombatEntry0215a0a4* SearchBothTables02079e2c(char*, int);
void* Clear12Bytes020e46c4(void*);
GameObject* GetCombatantWithFlag0x100(GameState*, int);
void SetIndexedName02046574(Obj02046574*, int, char*);
void InitObjFromCombatantId020e4bf4(void*, int);
int ConsumeCounter02048350(Obj02048350*, int);
int CheckField0NonZero(int*);
int GetFieldByKey020e0434(Container020e0310*, int);
int AppendString02042058(char*, const char*);
void StoreInArray0x8b0(StoreStruct*, int, int);
int GetByteField0x5721(GameState*);
extern "C" int* func_0202ae18();
extern "C" void func_02046380(void*);
extern "C" void func_02046608(void*, int, int, void*, int, int, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);

static inline char* GetCombatantName0215a0a4(GameObject* object) {
    char* name = (char*)object->baseStats_;
    return name;
}

// USA: func_ov002_0215a0a4
extern "C" ARM void func_ov002_0215a0a4(CombatMessageMenu0215a0a4* menu, CombatCommand0215a0a4* command, int apply) {
    MessageBuffer0215a0a4* buffer;
    Dispatch020e3428(GetData02153637(), 1);
    GameState* game = GameState::GetInstance();
    Obj02046574* formatter = GetGlobalField0x1c020421a0();
    int* state = func_0202ae18();
    CombatEntry0215a0a4* entry = SearchBothTables02079e2c(GetData02108e10(), menu->command);
    if (entry == NULL) return;
    memset(menu->primary, 0, 0x960);
    memset(menu->backup, 0, 0x960);
    func_02046380(formatter);
    buffer = menu->primary;
    Clear12Bytes020e46c4(&menu->actorReference);
    Clear12Bytes020e46c4(&menu->targetReference);
    GameObject* actor = GetCombatantWithFlag0x100(game, command->actorId);
    if (actor != NULL) {
        SetIndexedName02046574(formatter, 0, (char*)actor->baseStats_);
        InitObjFromCombatantId020e4bf4(&menu->actorReference, command->actorId);
        formatter->actor = &menu->actorReference;
    }
    SetIndexedName02046574(formatter, 1, entry->name);
    if (menu->command == 0x1e || menu->command == 0x1f || menu->command == 0x20 || menu->command == 0x21 || menu->command == 0x23 || menu->command == 0x26 || menu->command == 0x27) {
        menu->active = 1;
        menu->messageId = 0x232d;
        menu->field_1c2a = -1;
        GameObject* partyMember = game->GetPartyMemberByIndex(menu->partyIndex);
        int consume = 0;
        if (apply && partyMember != NULL) {
            if (menu->command == 0x1e || menu->command == 0x1f || menu->command == 0x20 || menu->command == 0x21) {
                menu->detailMessage = 0x232c;
                consume = 1;
            } else if (menu->command == 0x23) {
                menu->detailMessage = 0x794b;
                consume = 1;
            } else if (menu->command == 0x27 || menu->command == 0x26) {
                menu->detailMessage = 0x2336;
                consume = 1;
            }
        } else {
            if (partyMember == NULL) {
                menu->messageId = 0x232d;
                menu->detailMessage = 0x232b;
            } else if (((PartyMember0215a0a4*)partyMember)->status->flags & 1) {
                if (menu->command == 0x26) {
                    menu->detailMessage = 0x2337;
                    consume = 1;
                } else {
                    menu->detailMessage = 0x232b;
                }
            } else if (command->results[0].type == 1) {
                menu->messageId = 0x232d;
                menu->detailMessage = 0x232b;
            } else {
                menu->messageId = 0x2333;
                menu->detailMessage = 0x2334;
            }
        }
        menu->x = 0x26;
        menu->y = 0x11;
        menu->field_1bc0 = 0;
        if (consume) {
            ConsumeCounter02048350((Obj02048350*)actor, entry->cost);
            if (CheckField0NonZero(state))
                func_ov017_021c9e00(menu->actorId, 0, 0, 1);
        }
        return;
    }
    if (menu->command != 0x22 && menu->command != 0x310) return;
    if (apply) {
        func_02046608(formatter, 0xc, GetFieldByKey020e0434(&menu->messages, 0x232d), buffer->scratch, 0xe3, 0, 1);
        AppendString02042058(menu->primary->text, buffer->scratch);
        CommandResult0215a0a4* results = command->results;
        for (int index = 0; index < command->targetCount; ++index) {
            int message;
            if (results[index].type == 3) message = 0x232c;
            else message = 0x233a;
            if (message >= 0) {
                GameObject* target = GetCombatantWithFlag0x100(game, command->targetIds[index]);
                if (target != NULL) {
                    func_02046380(formatter);
                    SetIndexedName02046574(formatter, 2, GetCombatantName0215a0a4(target));
                    InitObjFromCombatantId020e4bf4(&menu->targetReference, command->targetIds[index]);
                    formatter->target = &menu->targetReference;
                    StoreInArray0x8b0((StoreStruct*)formatter, 9, target->obj3D_.unknown_4_);
                    func_02046608(formatter, 0xc, GetFieldByKey020e0434(&menu->messages, message), buffer->scratch, 0xe3, 0, 1);
                    AppendString02042058(menu->primary->text, (const char*)GetFieldByKey020e0434(&menu->messages, 8));
                    AppendString02042058(menu->primary->text, buffer->scratch);
                }
            }
        }
        ConsumeCounter02048350((Obj02048350*)actor, entry->cost);
        if (CheckField0NonZero(state))
            func_ov017_021c9e00(menu->actorId, 0, 0, 1);
    } else {
        GameObject* target = game->GetUnknownGameObject();
        if (target != NULL) {
            SetIndexedName02046574(formatter, 2, (char*)target->baseStats_);
            InitObjFromCombatantId020e4bf4(&menu->targetReference, target->obj3D_.unknown_4_);
            formatter->target = &menu->targetReference;
        }
        AppendString02042058(buffer->scratch, (const char*)GetFieldByKey020e0434(&menu->messages, 0x2333));
        AppendString02042058(buffer->scratch, (const char*)GetFieldByKey020e0434(&menu->messages, 8));
        if (GetByteField0x5721(game) == 1)
            AppendString02042058(buffer->scratch, (const char*)GetFieldByKey020e0434(&menu->messages, 0x2334));
        else
            AppendString02042058(buffer->scratch, (const char*)GetFieldByKey020e0434(&menu->messages, 0x2335));
        func_02046608(formatter, 0xc, (int)buffer->scratch, menu->primary, 0xe3, 0, 1);
    }
    menu->ready = 1;
    memcpy(menu->backup, menu->primary, 0x960);
    menu->detailMessage = -1;
    menu->active = 0;
}
