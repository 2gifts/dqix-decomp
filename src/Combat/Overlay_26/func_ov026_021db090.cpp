#include <globaldefs.h>

#if defined(jpn)
enum { kBattleOffset = 0x218, kStateToListPadding = 0x28f0, kListToModePadding = 0x236c, kWindowActiveOffset = 0x868, kWindowFlagsOffset = 0x1789, kAfterBusyOffset = 0x874, kWindowFirstFlagOffset = 0x17e1, kAfterFlagsOffset = 0x178a, kWindowFinalFlagOffset = 0x17ee, kAfterTwoFlagsOffset = 0x17e3 };
#else
enum { kBattleOffset = 0x29c, kStateToListPadding = 0x28b0, kListToModePadding = 0x2138, kWindowActiveOffset = 0x998, kWindowFlagsOffset = 0x195b, kAfterBusyOffset = 0x9a4, kWindowFirstFlagOffset = 0x19b1, kAfterFlagsOffset = 0x195c, kWindowFinalFlagOffset = 0x19be, kAfterTwoFlagsOffset = 0x19b3 };
#endif

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
    char pad0[kBattleOffset];
    BattleState* battle;
    PartyState* party;
    char pad2a4[0xc08];
    int state;
    char padeb0[kStateToListPadding];
    Container_021dae60 list;
    char pad3818[kListToModePadding];
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
    char pad4[kWindowActiveOffset - 4];
    int active;
    char pad99c[4];
    int busy;
    char pad9a4[kWindowFlagsOffset - kAfterBusyOffset];
    unsigned char flags;
    char pad195c[kWindowFirstFlagOffset - kAfterFlagsOffset];
    unsigned char b19b1;
    unsigned char b19b2;
    char pad19b3[kWindowFinalFlagOffset - kAfterTwoFlagsOffset];
    unsigned char b19be;
};

struct TextBuffers {
    char pad0[0x5c];
    char* text;
};

extern "C" void __clear(void* p, int size);
MessageWindow* GetGlobalField0x1c020421a0();
int IsFlag10088Set(struct S_10088*);
void InitObjFromCombatant020e4c74(void*, GameObject*);
void SetField0x158(void*, int);
void EnqueueEventTag86_021c9ad4(unsigned short);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
void ReinitController02043204(char*);
void SetFieldsAndSignalData02184220(void*, int);
CommandSlot* FindSlotById_021dae60(Container_021dae60*, int);

extern "C" {
int func_ov000_0215e9fc(BattleState*, short*, int, int);
void func_ov000_02162c14(BattleWork*, int, TargetInfo*);
void func_020dd0b0(int, char*);
GameResources* func_ov017_0218b5b0();
void func_02012fe4();
void func_ov017_021a23b0(GameResources*, unsigned short);
#if defined(jpn)
void func_0204500c(MessageWindow*, char*, int);
#else
void func_0204500c(MessageWindow*, char*, int, int);
#endif
void func_02043124(MessageWindow*);
void func_ov000_02160da0(BattleWork*);
}

#if defined(jpn)
extern char data_ov026_021df3fa[];
extern char data_ov026_021df3ff[];
extern char data_ov026_021df423[];
extern char data_ov026_021df465[];
#endif

extern char data_ov026_021dedee[];
extern IdList data_ov026_021de6bc;
extern Obj0205eaa0 data_02108760;

// USA: func_ov026_021db090
extern "C" ARM void func_ov026_021db090(BattleWork* self) {
    GameState* gs = GameState::GetInstance();
    MessageWindow* win = GetGlobalField0x1c020421a0();

    if (self->state == 0) {
#if defined(jpn)
        char message[0x80];
        char name[0x40];
#else
        char message[0x100];
        ObjRef ref;
        unsigned short name[0x20];
#endif
        TargetInfo info;
        short ids[4];
        IdList picked;
        int n;
#if defined(jpn)
        int count;
        int pluralCount;
#else
        int count;
#endif
        int i;
        char* text;

#if defined(jpn)
        gs->GetProtagonist();
#else
        sprintf(message, data_ov026_021dedee);
#endif
        __clear(name, sizeof(name));
        n = func_ov000_0215e9fc(self->battle, ids, 4, 0);
        picked = data_ov026_021de6bc;
#if defined(jpn)
        count = 0;
        pluralCount = 0;
#else
        count = 0;
#endif
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
#if defined(jpn)
            count++;
            pluralCount++;
#else
            count++;
#endif
        }
#if defined(jpn)
        GameObject* first = gs->GetCombatantByIndex(picked.ids[0]);
        if (first != NULL) {
            strcpy(name, (char*)first->baseStats_);
        }
        if (pluralCount > 1) {
            strcat(name, data_ov026_021df3fa);
        }
#else
        InitObjFromCombatant020e4c74(&ref, gs->GetPartyMemberByIndex(picked.ids[0]));
#endif

        if (self->mode == 2) {
#if defined(jpn)
            sprintf(message, data_ov026_021df3ff, name);
#else
            text = ((TextBuffers*)GetGlobalField0x1c020421a0())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(1, text);
            strcat(message, text);
#endif

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
            EnqueueEventTag86_021c9ad4(netId);
            func_ov017_021a23b0(res, netId);
        } else if (self->mode == 4) {
#if defined(jpn)
            sprintf(message, data_ov026_021df423, name);
#else
            text = ((TextBuffers*)GetGlobalField0x1c020421a0())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(2, text);
            strcat(message, text);
#endif
        } else {
#if defined(jpn)
            sprintf(message, data_ov026_021df465, name);
#else
            text = ((TextBuffers*)GetGlobalField0x1c020421a0())->text;
            memset(text, 0, 0x960);
            func_020dd0b0(3, text);
            strcat(message, text);
#endif
        }

#if defined(jpn)
        func_0204500c(win, message, 0);
#else
        win->source = &ref;
        func_0204500c(win, message, 0, 0xe3);
#endif
        win->b19b1 = 0;
        win->b19b2 = 0;
        win->b19be = 1;
        win->flags |= 2;
        win->active = 1;
        DispatchWithShortB4_0205eaa0(&data_02108760, 9, 0);
        self->state++;
    } else if (win->busy == 0) {
        self->state++;
        if (self->state >= 0x1e) {
            ReinitController02043204((char*)win);
            func_02043124(win);
            if (self->mode == 2) {
                SetFieldsAndSignalData02184220(self, 4);
            } else {
                for (int i = 0; i < 4; i++) {
                    CommandSlot* slot = FindSlotById_021dae60(&self->list, i);
                    if (slot != NULL && slot->kind == 6) {
                        slot->selections[slot->selection] = 0x66;
                    }
                }
                func_ov000_02160da0(self);
            }
        }
    }
}
