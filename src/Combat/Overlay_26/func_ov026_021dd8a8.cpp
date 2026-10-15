#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct S_10088;
struct FlagObj_021dd3c4;
struct StoreStruct;
struct Container_021dae60;

struct GroupEntry {
    unsigned short leader;
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char unkA_4 : 4;
    unsigned char unkB[0xd];
};

struct GroupTable {
    unsigned char unk0;
    unsigned char kind : 4;
    unsigned char numGroups : 2;
    unsigned char unk1_6 : 2;
    unsigned char unk2[2];
    GroupEntry entries[4];
};

struct BattleState {
    char pad0[0x81b0];
    GroupTable groups;
    char pad8214[0xc10];
    int busy;
    char pad8e28[0x21];
    unsigned char kind;
};

struct PartyState {
    char pad0[0x8];
    unsigned short netId;
};

struct ObjRef {
    int data[3];
};

struct StatusBlock {
    unsigned int flags;
};

struct CombatantView {
    char pad0[0x130];
    StatusBlock* status;
    char pad134[0x14];
    void* owner;
};

struct ViewInfo {
    char pad0[0xc];
    int count;
};

struct SideInfo {
    char pad0[0x955];
    unsigned char side;
};

struct MessageWork {
    char pad0[0x20];
    ObjRef* refs[4];
    unsigned char total;
    unsigned char ready;
    char pad32[0x5c - 0x32];
    char* text;
    char pad60[0x998 - 0x60];
    int active;
    char pad99c[0x195b - 0x99c];
    unsigned char flags;
    char pad195c[0x19b1 - 0x195c];
    unsigned char b19b1;
    unsigned char b19b2;
    char pad19b3[0x19d7 - 0x19b3];
    unsigned char b19d7;
};

extern "C" void __clear(void*, int);
extern "C" void func_02046380(MessageWork*);
extern "C" void func_020e4ce8(ObjRef*, GameObject*, int);
extern "C" ViewInfo* func_ov017_021b8478(void*);
extern "C" void* func_ov017_021b8468(void*);
extern "C" void func_020dd0b0(int, char*);
extern "C" void func_0204500c(MessageWork*, char*, int, int);
extern "C" void func_02042b98(MessageWork*, int, int, int, int);
MessageWork* GetGlobalField0x1c020421a0();
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
int IsFlag10088Set_02010088(S_10088*);
int IsFlagBit8192Set_021dd3c4(FlagObj_021dd3c4*);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
unsigned char CopyOutRegion0x571d_020114ec(char*, void*);
void* GetActiveCombatWork_ov000_02160130();
void* GetOffsetPtr02160f08(void*);
void* FindSlotById_021dae60(Container_021dae60*, int);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
char* InitAndClearBuffer_021d8a78(void*);

extern signed char data_ov026_021de6a6[];
extern signed char data_ov026_021de6a8[];
extern char data_ov026_021deebd[];
extern signed char data_ov026_021de6a2[];
extern char data_ov026_021deec7[];
extern char data_ov026_021deed8[];

// USA: func_ov026_021dd8a8
extern "C" ARM void func_ov026_021dd8a8(BattleState* battle, PartyState* party) {
    char message[0x300];
    ObjRef refs[3];
    unsigned short leaders[3];
    unsigned char found[3];
    unsigned char kinds[3];
    unsigned char ids[4];
    GameState* gs;
    void* zone;
    MessageWork* win;
    int n;
    GroupEntry* e;
    int viewCount;
    int g;
    int extra;
    int j;
    int none;
    unsigned char idle;
    GroupTable* groups;
    int i;
    unsigned char present;
    int count;
    void* slots;
    GameResources* res;
    ViewInfo* view;
    char* text;
    int dup;
    int msgId;

    gs = GameState::GetInstance();
    win = GetGlobalField0x1c020421a0();
    if (battle->busy != 0) {
        return;
    }
    func_02046380(win);
    groups = &battle->groups;
    n = 0;
    __clear(found, sizeof(found));
    __clear(kinds, sizeof(kinds));
    for (e = groups->entries, g = 0; g < groups->numGroups; e++, g++) {
        dup = 0;
        for (int k = 0; k < n; k++) {
            if (e->leader == leaders[k] || e->leader == 0) {
                if (e->leader == leaders[k]) {
                    found[k] = 1;
                }
                dup = 1;
                break;
            }
        }
        if (dup) {
            continue;
        }
        leaders[n] = e->leader;
        for (j = 0; j < e->count; j++) {
            GameObject* c = GetCombatantWithFlag0x400_0200fea4(gs, e->ids[j] + 0xc0);
            if (c == NULL || IsFlag10088Set_02010088((S_10088*)c) || IsFlagBit8192Set_021dd3c4((FlagObj_021dd3c4*)c)) {
                continue;
            }
            if (((CombatantView*)c)->owner == NULL) {
                continue;
            }
            ObjRef* ref = &refs[n];
            func_020e4ce8(ref, c, 1);
            ref->data[2] &= ~0x80000000;
            win->refs[n] = ref;
            kinds[n] = e->count;
            n++;
            break;
        }
    }

    res = func_ov017_0218b5b0();
    zone = NULL;
    view = NULL;
    none = (int)zone;
    if (res != NULL) {
        zone = res->unknown_ptr_3718;
    }
    viewCount = none - 1;
    if (zone != NULL) {
        view = func_ov017_021b8478(zone);
    }
    if (view != NULL) {
        viewCount = view->count;
    }
    extra = 0;
    if (kinds[0] > 1 || found[0] == 1) {
        StoreInArray0x8b0_020465c0((StoreStruct*)win, 0, 0);
        extra = 1;
    } else {
        StoreInArray0x8b0_020465c0((StoreStruct*)win, 0, 1);
    }

    count = CopyOutRegion0x571d_020114ec((char*)gs, ids);
    idle = 0;
    present = 0;
    slots = GetOffsetPtr02160f08(GetActiveCombatWork_ov000_02160130());
    for (i = 0; i < count; i++) {
        GameObject* c = gs->GetCombatantByIndex(ids[i]);
        FindSlotById_021dae60((Container_021dae60*)slots, ids[i]);
        if (c == NULL) {
            continue;
        }
        if (!TestBitAt0x34_020a35e0((unsigned char*)party, ids[i])) {
            continue;
        }
        present++;
        if (!(((CombatantView*)c)->status->flags & 1)) {
            idle++;
        }
    }
    win->total = present;
    win->ready = idle;

    switch (n) {
    case 1:
        msgId = 6;
        break;
    case 2:
        msgId = 7;
        {
            int arg = 1;
            if (kinds[1] > 1 || found[1] == 1) {
                arg = 0;
            }
            StoreInArray0x8b0_020465c0((StoreStruct*)win, 1, arg);
        }
        extra = 1;
        break;
    default:
        if (viewCount == 0x36 || viewCount == 0x43 || viewCount == 0x50) {
            msgId = 8;
        } else {
            extra = 1;
            msgId = 9;
        }
        break;
    }

    text = GetGlobalField0x1c020421a0()->text;
    memset(text, 0, 0x960);
    func_020dd0b0(msgId, text);
    strcpy(message, text);
    if (battle->kind == 1) {
        SideInfo* info = (SideInfo*)GetOffsetPtr02160f08(func_ov017_021b8468(zone));
        unsigned char side = party->netId % 2;
        if (info != NULL) {
            info->side = side;
        }
        msgId = data_ov026_021de6a6[side];
        if (extra) {
            msgId = data_ov026_021de6a8[side];
            win->b19d7 = 1;
        }
        text = GetGlobalField0x1c020421a0()->text;
        memset(text, 0, 0x960);
        func_020dd0b0(msgId, text);
        strcat(message, text);
    } else if (battle->kind == 2) {
        strcat(message, data_ov026_021deebd);
        strcat(message, InitAndClearBuffer_021d8a78((void*)data_ov026_021de6a2[party->netId % 2]));
        if (extra) {
            win->b19d7 = 1;
        }
    }
    if (battle->kind != 0) {
        strcat(message, data_ov026_021deec7);
    } else {
        strcat(message, data_ov026_021deed8);
    }
    func_0204500c(win, message, 0, 0xe3);
    win->b19b1 = 0;
    func_02042b98(win, 2, 0x92, 0xfc, 0x4a);
    win->b19b2 = 0;
    win->flags |= 2;
    win->active = 1;
}
