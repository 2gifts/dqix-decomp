#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

#if defined(jpn)
#define data_ov024_021fe748 data_ov024_021fef14
#endif

struct Act_021eb5d0;
struct Src_021eb5d0;
struct Rec_021eb5d0;
struct Battle_02153e78;
struct FlagObj_021dd010;

struct Action_021eaa50 {
    char pad0[8];
    unsigned int mpCost : 8;
    unsigned int p8 : 20;
    unsigned int noMp : 1;
    unsigned int p8b : 3;
    unsigned int p0c;
    unsigned int flags10;
    unsigned int p14;
    unsigned int p18a : 12;
    unsigned int f18 : 4;
    unsigned int p18b : 16;
    unsigned int p1c;
    unsigned int p20;
    unsigned int p24;
    unsigned int p28;
    unsigned int p2ca : 10;
    unsigned int f2c : 4;
    unsigned int p2cb : 18;
    char p30[2];
    short f32;
};

struct Tbl8_021eaa50 {
    short v[8];
};

extern Tbl8_021eaa50 data_ov024_021fe748;

GameObject* GetCombatantWithFlag0x400ByID(int, int);
extern "C" int func_ov000_02153e78(Battle_02153e78*, short*, int, int, int);
int IsSpecialStateValue_02159c58(void*, int);
extern "C" int func_ov000_0215e9fc(char*, short*, int, unsigned int);
extern "C" int func_ov000_02159cb4(void*, int);
int IsCombatantFlag2Mask512_021eadfc(GameObject*);
unsigned int AdjustValueByFieldFlag(void*, unsigned int);
int IsFlagBit8Set_021dd010(FlagObj_021dd010*);
int IsIdOrEffectMatchTarget0215fd24(int, int);
GameObject* GetCombatantWithFlag0x1000(GameState*, int);

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021eaa50
// KEEP-NAME
// JPN: func_ov024_021eb21c
extern "C" ARM int func_ov024_021eaa50(Act_021eb5d0* act, Src_021eb5d0* src,
                                      Rec_021eb5d0* record, int flag4) {
    char* a0 = (char*)act;
    char* sb = (char*)src;
    Action_021eaa50* action = (Action_021eaa50*)record;
    GameState* gs = GameState::GetInstance();
    short id = *(short*)(*(char**)(sb + 0x10) + 0x20);
    GameObject* self = GetCombatantByID((int)*(char**)(a0 + 0x10), id);
    Tbl8_021eaa50 tbl = data_ov024_021fe748;

    if (*(unsigned short*)sb == 0x153) {
        GameObject* c = GetCombatantWithFlag0x400ByID((int)*(char**)(a0 + 0x10), *(short*)(*(char**)(sb + 0x10) + 0x20));
        if (c == 0) {
            *(unsigned short*)sb = 2;
            *(unsigned char*)(sb + 9) = 0;
            return 2;
        }
        if (func_ov000_02153e78((Battle_02153e78*)*(char**)(a0 + 0x10), tbl.v, 8, *((unsigned char*)c + 0x17c), 1) != 8) {
            *(unsigned short*)sb = 2;
            *(unsigned char*)(sb + 9) = 0;
            return 2;
        }
    }
    if (*(unsigned short*)sb == 0x31a) {
        GameObject* c = GetCombatantWithFlag0x400ByID((int)*(char**)(a0 + 0x10), *(short*)(*(char**)(sb + 0x10) + 0x20));
        if (c == 0) {
            *(unsigned short*)sb = 2;
            *(unsigned char*)(sb + 9) = 0;
            return 2;
        }
        if (func_ov000_02153e78((Battle_02153e78*)*(char**)(a0 + 0x10), tbl.v, 8, *((unsigned char*)c + 0x17c), 1) != 3) {
            *(unsigned short*)sb = 2;
            *(unsigned char*)(sb + 9) = 0;
            return 2;
        }
    }
    if (IsSpecialStateValue_02159c58(*(char**)(a0 + 0x10), *(unsigned short*)sb)) {
        if (func_ov000_0215e9fc(*(char**)(a0 + 0x10), tbl.v, 8, 1) != 4) {
            *(unsigned char*)(sb + 9) = 0;
            *(unsigned short*)sb = (unsigned short)func_ov000_02159cb4(*(char**)(a0 + 0x10), *(short*)(*(char**)(sb + 0x10) + 0x20));
            return *(unsigned short*)sb;
        }
    }

    int below = 0;
    if (!IsCombatantFlag2Mask512_021eadfc(self) && flag4 == 0 && !action->noMp) {
        short v6 = (short)action->mpCost;
        if (IsPartyMember(id)) {
            v6 = (short)AdjustValueByFieldFlag(
                GetCombatantWithFlag0x100(gs, id), (unsigned int)v6);
        }
        if (action->mpCost < 0xff) {
            if (self->currentStats_->primaryStats.currMP < v6) below = 1;
        } else {
            if (self->currentStats_->primaryStats.currMP == 0) below = 1;
        }
    }
    if (below) {
        int nv = 0x1f8;
        if (action->f18 == 1) nv = 0x3a9;
        unsigned short v = *(unsigned short*)sb;
        *(unsigned short*)(sb + 2) = v;
        *(unsigned char*)(sb + 9) = 0;
        *(unsigned short*)sb = nv;
        if (action->flags10 & 1) *((unsigned char*)self->currentStats_ + 0x3c) |= 8;
        else *((unsigned char*)self->currentStats_ + 0x3c) |= 0x20;
        return nv;
    }

    if ((action->flags10 & 1) && IsFlagBit8Set_021dd010((FlagObj_021dd010*)self)) {
        unsigned short v = *(unsigned short*)sb;
        int nv = 0x392;
        *(unsigned short*)(sb + 2) = v;
        *(unsigned char*)(sb + 9) = 0;
        *(unsigned short*)sb = nv;
        *((unsigned char*)self->currentStats_ + 0x3c) |= 8;
        return nv;
    }

    if (action->f2c == 6 && IsPartyMember(id)) {
        int found = 0;
        if (IsIdOrEffectMatchTarget0215fd24((int)*(char**)(a0 + 0x10), id)) {
            void* arr = GetPtrField0x2a04(gs);
            if (*(unsigned int*)((char*)arr + 0xf6c) < action->f32) found = 1;
        } else {
            GameObject* p = GetCombatantWithFlag0x1000(gs, id);
            if (p != 0) {
                if (((int*)(*(char**)(a0 + 0x10) + 0x8e84))[0] < action->f32) found = 1;
            } else {
                if (((int*)(*(char**)(a0 + 0x10) + 0x8e84))[id] < action->f32) found = 1;
            }
        }
        if (found) {
            unsigned short v = *(unsigned short*)sb;
            int nv = 0x3a7;
            *(unsigned short*)(sb + 2) = v;
            *(unsigned char*)(sb + 9) = 0;
            *(unsigned short*)sb = nv;
            return nv;
        }
    }
    return *(unsigned short*)sb;
}
