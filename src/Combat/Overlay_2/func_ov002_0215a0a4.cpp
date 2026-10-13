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
extern "C" void _Z16Dispatch020e3428Pvi(void*, int);
extern "C" Obj02046574* _Z26GetGlobalField0x1c020421a0v();
char* GetData02108e10();
extern "C" CombatEntry0215a0a4* _Z24SearchBothTables02079e2cPci(char*, int);
extern "C" void* _Z20Clear12Bytes020e46c4Pv(void*);
GameObject* GetCombatantWithFlag0x100(GameState*, int);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(Obj02046574*, int, char*);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void*, int);
extern "C" int _Z22ConsumeCounter02048350P11Obj02048350i(Obj02048350*, int);
int CheckField0NonZero(int*);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310*, int);
extern "C" int _Z20AppendString02042058PcPKc(char*, const char*);
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
    _Z16Dispatch020e3428Pvi(GetData02153637(), 1);
    GameState* game = GameState::GetInstance();
    Obj02046574* formatter = _Z26GetGlobalField0x1c020421a0v();
    int* state = func_0202ae18();
    CombatEntry0215a0a4* entry = _Z24SearchBothTables02079e2cPci(GetData02108e10(), menu->command);
    if (entry == NULL) return;
    memset(menu->primary, 0, 0x960);
    memset(menu->backup, 0, 0x960);
    func_02046380(formatter);
    buffer = menu->primary;
    _Z20Clear12Bytes020e46c4Pv(&menu->actorReference);
    _Z20Clear12Bytes020e46c4Pv(&menu->targetReference);
    GameObject* actor = GetCombatantWithFlag0x100(game, command->actorId);
    if (actor != NULL) {
        _Z22SetIndexedName02046574P11Obj02046574iPc(formatter, 0, (char*)actor->baseStats_);
        _Z30InitObjFromCombatantId020e4bf4Pvi(&menu->actorReference, command->actorId);
        formatter->actor = &menu->actorReference;
    }
    _Z22SetIndexedName02046574P11Obj02046574iPc(formatter, 1, entry->name);
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
            _Z22ConsumeCounter02048350P11Obj02048350i((Obj02048350*)actor, entry->cost);
            if (CheckField0NonZero(state))
                func_ov017_021c9e00(menu->actorId, 0, 0, 1);
        }
        return;
    }
    if (menu->command != 0x22 && menu->command != 0x310) return;
    if (apply) {
        func_02046608(formatter, 0xc, _Z21GetFieldByKey020e0434P17Container020e0310i(&menu->messages, 0x232d), buffer->scratch, 0xe3, 0, 1);
        _Z20AppendString02042058PcPKc(menu->primary->text, buffer->scratch);
        CommandResult0215a0a4* results = command->results;
        for (int index = 0; index < command->targetCount; ++index) {
            int message;
            if (results[index].type == 3) message = 0x232c;
            else message = 0x233a;
            if (message >= 0) {
                GameObject* target = GetCombatantWithFlag0x100(game, command->targetIds[index]);
                if (target != NULL) {
                    func_02046380(formatter);
                    _Z22SetIndexedName02046574P11Obj02046574iPc(formatter, 2, GetCombatantName0215a0a4(target));
                    _Z30InitObjFromCombatantId020e4bf4Pvi(&menu->targetReference, command->targetIds[index]);
                    formatter->target = &menu->targetReference;
                    StoreInArray0x8b0((StoreStruct*)formatter, 9, target->obj3D_.unknown_4_);
                    func_02046608(formatter, 0xc, _Z21GetFieldByKey020e0434P17Container020e0310i(&menu->messages, message), buffer->scratch, 0xe3, 0, 1);
                    _Z20AppendString02042058PcPKc(menu->primary->text, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&menu->messages, 8));
                    _Z20AppendString02042058PcPKc(menu->primary->text, buffer->scratch);
                }
            }
        }
        _Z22ConsumeCounter02048350P11Obj02048350i((Obj02048350*)actor, entry->cost);
        if (CheckField0NonZero(state))
            func_ov017_021c9e00(menu->actorId, 0, 0, 1);
    } else {
        GameObject* target = game->GetUnknownGameObject();
        if (target != NULL) {
            _Z22SetIndexedName02046574P11Obj02046574iPc(formatter, 2, (char*)target->baseStats_);
            _Z30InitObjFromCombatantId020e4bf4Pvi(&menu->targetReference, target->obj3D_.unknown_4_);
            formatter->target = &menu->targetReference;
        }
        _Z20AppendString02042058PcPKc(buffer->scratch, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&menu->messages, 0x2333));
        _Z20AppendString02042058PcPKc(buffer->scratch, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&menu->messages, 8));
        if (GetByteField0x5721(game) == 1)
            _Z20AppendString02042058PcPKc(buffer->scratch, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&menu->messages, 0x2334));
        else
            _Z20AppendString02042058PcPKc(buffer->scratch, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&menu->messages, 0x2335));
        func_02046608(formatter, 0xc, (int)buffer->scratch, menu->primary, 0xe3, 0, 1);
    }
    menu->ready = 1;
    memcpy(menu->backup, menu->primary, 0x960);
    menu->detailMessage = -1;
    menu->active = 0;
}
