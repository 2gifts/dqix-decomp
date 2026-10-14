#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/ActionDataTables.h"
#include <std_library_functions.h>

struct Obj02048350;
struct StoreStruct;
struct Obj02046574 {
    void* actor;
    unsigned char unknown_4[12];
    void* target;
};
struct CommandEntry0215a0a4 {
    char* name;
    int unknown_4;
    unsigned int counter : 8;
    unsigned int unused : 24;
};
struct BattleTextState0215a0a4 {
    unsigned char unknown_0[0xbb8];
    int state;
    int nextState;
    int timer;
    unsigned char unknown_bc4[12];
    char* text;
    char* textCopy;
};
struct BattleMessage0215a0a4 {
    unsigned char unknown_0[8];
    unsigned char actorName[12];
    unsigned char targetName[12];
    Container020e0310 texts;
    unsigned char unknown_28[0x1000 - 0x28];
    BattleTextState0215a0a4 textState;
    unsigned char unknown_1bd8[0x1c20 - 0x1bd8];
    signed char actorId;
    signed char partyIndex;
    unsigned char unknown_1c22[4];
    short command;
    short messageKey;
    short alternateKey;
    unsigned char unknown_1c2c[5];
    unsigned char pending;
    unsigned char unknown_1c32[0x2488 - 0x1c32];
    short secondaryKey;
    unsigned char active;
};
struct ActionResult0215a0a4 {
    unsigned char kind;
    unsigned char unknown_1[5];
};
struct BattleEvent0215a0a4 {
    unsigned char unknown_0[2];
    signed char actor;
    unsigned char count;
    signed char targets[4];
    ActionResult0215a0a4 results[4];
};
struct PartyFlags0215a0a4 {
    unsigned char unknown_0[0x130];
    unsigned int* flags;
};

void* GetData02153637();
extern "C" void _Z16Dispatch020e3428Pvi(void*, int);
extern "C" Obj02046574* _Z26GetGlobalField0x1c020421a0v();
extern "C" CommandEntry0215a0a4* _Z24SearchBothTables02079e2cPci(char*, int);
extern "C" void* _Z20Clear12Bytes020e46c4Pv(void*);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(Obj02046574*, int, char*);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void*, int);
extern "C" int _Z22ConsumeCounter02048350P11Obj02048350i(Obj02048350*, int);
int CheckField0NonZero(int*);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310*, int);
extern "C" int _Z20AppendString02042058PcPKc(char*, const char*);
void StoreInArray0x8b0(StoreStruct*, int, int);
extern "C" int* func_0202ae18();
extern "C" void func_02046380(void*);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_02046608(void*, int, int, void*, int, int, int);

static inline char* CombatantName0215a0a4(GameObject* target) { SDK_NULL_ASSERT(target); return target->baseStats_->unk; }

// USA: func_ov002_0215a0a4
extern "C" ARM void func_ov002_0215a0a4(BattleMessage0215a0a4* self, BattleEvent0215a0a4* event, int any) {
    GameObject* target;
    int rejectedKey;
    int* state;
    GameObject* actor;
    ActionResult0215a0a4* results;
    char* buffer;
    signed char* targetIds;
    GameState* gs;
    Obj02046574* message;
    CommandEntry0215a0a4* entry;
    int index;
    _Z16Dispatch020e3428Pvi(GetData02153637(), 1);
    gs = GameState::GetInstance();
    message = _Z26GetGlobalField0x1c020421a0v();
    state = func_0202ae18();
    entry = _Z24SearchBothTables02079e2cPci((char*)GetData02108e10(), self->command);
    if (!entry) return;
    memset(self->textState.text, 0, 0x960);
    memset(self->textState.textCopy, 0, 0x960);
    func_02046380(message);
    buffer = self->textState.text;
    _Z20Clear12Bytes020e46c4Pv(self->actorName);
    _Z20Clear12Bytes020e46c4Pv(self->targetName);
    actor = GetCombatantWithFlag0x100(gs, event->actor);
    if (actor) {
        _Z22SetIndexedName02046574P11Obj02046574iPc(message, 0, actor->baseStats_->unk);
        _Z30InitObjFromCombatantId020e4bf4Pvi(self->actorName, event->actor);
        message->actor = self->actorName;
    }
    _Z22SetIndexedName02046574P11Obj02046574iPc(message, 1, entry->name);
    if (self->command == 0x1e || self->command == 0x1f || self->command == 0x20 ||
        self->command == 0x21 || self->command == 0x23 || self->command == 0x26 || self->command == 0x27) {
        self->active = 1;
        self->messageKey = 0x232d;
        self->alternateKey = -1;
        GameObject* party = gs->GetPartyMemberByIndex(self->partyIndex);
        int consumed = 0;
        if (any && party) {
            if (self->command == 0x1e || self->command == 0x1f || self->command == 0x20 || self->command == 0x21) {
                self->secondaryKey = 0x232c;
                consumed = 1;
            } else if (self->command == 0x23) {
                self->secondaryKey = 0x794b;
                consumed = 1;
            } else if (self->command == 0x27 || self->command == 0x26) {
                self->secondaryKey = 0x2336;
                consumed = 1;
            }
        } else if (!party) {
            self->messageKey = 0x232d;
            self->secondaryKey = 0x232b;
        } else if (*((PartyFlags0215a0a4*)party)->flags & 1) {
            if (self->command == 0x26) {
                self->secondaryKey = 0x2337;
                consumed = 1;
            } else {
                self->secondaryKey = 0x232b;
            }
        } else if (event->results[0].kind == 1) {
            self->messageKey = 0x232d;
            self->secondaryKey = 0x232b;
        } else {
            self->messageKey = 0x2333;
            self->secondaryKey = 0x2334;
        }
        self->textState.state = 0x26;
        self->textState.nextState = 0x11;
        self->textState.timer = 0;
        if (consumed) {
            _Z22ConsumeCounter02048350P11Obj02048350i((Obj02048350*)actor, entry->counter);
            if (CheckField0NonZero(state)) func_ov017_021c9e00(self->actorId, 0, 0, 1);
        }
        return;
    }
    if (self->command != 0x22 && self->command != 0x310) return;
    if (any) {
        func_02046608(message, 0xc, _Z21GetFieldByKey020e0434P17Container020e0310i(&self->texts, 0x232d), buffer + 0x860, 0xe3, 0, 1);
        _Z20AppendString02042058PcPKc(self->textState.text, buffer + 0x860);
        results = event->results;
        rejectedKey = 0x232c;
        index = 0;
        targetIds = event->targets;
        while (index < event->count) {
            int key = results[index].kind == 3 ? rejectedKey : 0x233a;
            if (key >= 0) {
                target = GetCombatantWithFlag0x100(gs, targetIds[index]);
                if (target) {
                    func_02046380(message);
                    _Z22SetIndexedName02046574P11Obj02046574iPc(message, 2, CombatantName0215a0a4(target));
                    _Z30InitObjFromCombatantId020e4bf4Pvi(self->targetName, targetIds[index]);
                    message->target = self->targetName;
                    StoreInArray0x8b0((StoreStruct*)message, 9, target->obj3D_.unknown_4_);
                    func_02046608(message, 0xc, _Z21GetFieldByKey020e0434P17Container020e0310i(&self->texts, key), buffer + 0x860, 0xe3, 0, 1);
                    _Z20AppendString02042058PcPKc(self->textState.text, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&self->texts, 8));
                    _Z20AppendString02042058PcPKc(self->textState.text, buffer + 0x860);
                }
            }
            index++;
        }
        _Z22ConsumeCounter02048350P11Obj02048350i((Obj02048350*)actor, entry->counter);
        if (CheckField0NonZero(state)) func_ov017_021c9e00(self->actorId, 0, 0, 1);
    } else {
        target = gs->GetUnknownGameObject();
        if (target) {
            _Z22SetIndexedName02046574P11Obj02046574iPc(message, 2, CombatantName0215a0a4(target));
            _Z30InitObjFromCombatantId020e4bf4Pvi(self->targetName, target->obj3D_.unknown_4_);
            message->target = self->targetName;
        }
        _Z20AppendString02042058PcPKc(buffer + 0x860, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&self->texts, 0x2333));
        _Z20AppendString02042058PcPKc(buffer + 0x860, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&self->texts, 8));
        if (GetByteField0x5721(gs) == 1)
            _Z20AppendString02042058PcPKc(buffer + 0x860, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&self->texts, 0x2334));
        else
            _Z20AppendString02042058PcPKc(buffer + 0x860, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(&self->texts, 0x2335));
        func_02046608(message, 0xc, (int)(buffer + 0x860), self->textState.text, 0xe3, 0, 1);
    }
    self->pending = 1;
    memcpy(self->textState.textCopy, self->textState.text, 0x960);
    self->secondaryKey = -1;
    self->active = 0;
}
