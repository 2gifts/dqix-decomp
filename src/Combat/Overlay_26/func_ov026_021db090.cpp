#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct BattleState;
struct GameResources;
struct Obj0205eaa0;

struct PartyState {
    char pad0[0x8];
    unsigned short netId;
};

struct Container_021dae60 {
    char pad0[0xb8];
};

struct CommandSlot {
    char pad0[0x10];
    unsigned char selections[8];
    signed char selection;
    char pad19[3];
    signed char kind;
};

struct BattleWork {
    char pad0[0x29c];
    BattleState* battle;
    PartyState* party;
    char pad2a4[0xc08];
    int state;
    char padeb0[0x28b0];
    Container_021dae60 list;
    char pad3818[0x2138];
    unsigned char mode;
};

struct TargetInfo {
    char pad0;
    unsigned char kind;
    char pad2[8];
};

struct IdList {
    short ids[4];
};

struct StatusBlock {
    char pad0[0x14];
    unsigned int flags;
};

struct CombatantView {
    char pad0[0x138];
    StatusBlock* status;
};

struct PartyList {
    char pad0[0xf78];
    unsigned char members[4];
    unsigned char count;
};

struct ObjRef {
    int data[3];
};

struct MessageWindow {
    ObjRef* source;
    char pad4[0x998 - 4];
    int active;
    char pad99c[4];
    int busy;
    char pad9a4[0x195b - 0x9a4];
    unsigned char flags;
    char pad195c[0x19b1 - 0x195c];
    unsigned char b19b1;
    unsigned char b19b2;
    char pad19b3[0x19be - 0x19b3];
    unsigned char b19be;
};

struct TextBuffers {
    char pad0[0x5c];
    char* text;
};

extern "C" void __clear(void* p, int size);
extern "C" MessageWindow* _Z26GetGlobalField0x1c020421a0v();
int IsFlag10088Set(struct S_10088*);
extern "C" void _Z28InitObjFromCombatant020e4c74PvP10GameObject(void*, GameObject*);
void SetField0x158(void*, int);
extern "C" void _Z26EnqueueEventTag86_021c9ad4t(unsigned short);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" void _Z24ReinitController02043204Pc(char*);
void SetFieldsAndSignalData02184220(void*, int);
extern "C" CommandSlot* _Z21FindSlotById_021dae60P18Container_021dae60i(Container_021dae60*, int);

extern "C" {
int func_ov000_0215e9fc(BattleState*, short*, int, int);
void func_ov000_02162c14(BattleWork*, int, TargetInfo*);
void func_020dd0b0(int, char*);
GameResources* func_ov017_0218b5b0();
void func_02012fe4();
void func_ov017_021a23b0(GameResources*, unsigned short);
void func_0204500c(MessageWindow*, char*, int, int);
void func_02043124(MessageWindow*);
void func_ov000_02160da0(BattleWork*);
}

extern char data_ov026_021dedee[];
extern IdList data_ov026_021de6bc;
extern Obj0205eaa0 data_02108760;

// USA: func_ov026_021db090
extern "C" ARM void func_ov026_021db090(BattleWork* self) {
    GameState* gs = GameState::GetInstance();
    MessageWindow* win = _Z26GetGlobalField0x1c020421a0v();

    if (self->state == 0) {
        char message[0x100];
        ObjRef ref;
        unsigned short name[0x20];
        TargetInfo info;
        short ids[4];
        IdList picked;
        int n;
        int count;
        int i;
        char* text;

        sprintf(message, data_ov026_021dedee);
        __clear(name, sizeof(name));
        n = func_ov000_0215e9fc(self->battle, ids, 4, 0);
        picked = data_ov026_021de6bc;
        count = 0;
        for (i = 0; i < n; i++) {
            GameObject* c = gs->GetCombatantByIndex(ids[i]);
            if (c == NULL || IsFlag10088Set((S_10088*)c)) {
                continue;
            }
            func_ov000_02162c14(self, ids[i], &info);
            if (info.kind != 6) {
                continue;
            }
            if (((CombatantView*)c)->status->flags & 0x80019) {
                continue;
            }
            picked.ids[count] = ids[i];
            count++;
        }
        _Z28InitObjFromCombatant020e4c74PvP10GameObject(&ref, gs->GetPartyMemberByIndex(picked.ids[0]));

        if (self->mode == 2) {
            text = ((TextBuffers*)_Z26GetGlobalField0x1c020421a0v())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(1, text);
            strcat(message, text);

            int j;
            PartyList* party;
            GameState* state;
            state = GameState::GetInstance();
            party = (PartyList*)GetPtrField0x2a04(state);
            for (j = 0; j < party->count; j++) {
                GameObject* member = GetCombatantWithFlag0x100(state, party->members[j]);
                if (member != NULL) {
                    SetField0x158(member, 2);
                }
            }
            GameResources* res = func_ov017_0218b5b0();
            func_02012fe4();
            unsigned short netId = self->party->netId;
            _Z26EnqueueEventTag86_021c9ad4t(netId);
            func_ov017_021a23b0(res, netId);
        } else if (self->mode == 4) {
            text = ((TextBuffers*)_Z26GetGlobalField0x1c020421a0v())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(2, text);
            strcat(message, text);
        } else {
            text = ((TextBuffers*)_Z26GetGlobalField0x1c020421a0v())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(3, text);
            strcat(message, text);
        }

        win->source = &ref;
        func_0204500c(win, message, 0, 0xe3);
        win->b19b1 = 0;
        win->b19b2 = 0;
        win->b19be = 1;
        win->flags |= 2;
        win->active = 1;
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 9, 0);
        self->state++;
    } else if (win->busy == 0) {
        self->state++;
        if (self->state >= 0x1e) {
            _Z24ReinitController02043204Pc((char*)win);
            func_02043124(win);
            if (self->mode == 2) {
                SetFieldsAndSignalData02184220(self, 4);
            } else {
                for (int i = 0; i < 4; i++) {
                    CommandSlot* slot = _Z21FindSlotById_021dae60P18Container_021dae60i(&self->list, i);
                    if (slot != NULL && slot->kind == 6) {
                        slot->selections[slot->selection] = 0x66;
                    }
                }
                func_ov000_02160da0(self);
            }
        }
    }
}
