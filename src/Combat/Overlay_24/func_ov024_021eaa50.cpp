#include <globaldefs.h>

// USA: func_ov024_021eaa50
struct GameState;
struct GameObject;

struct Battle_021eaa50 {
    char pad0[0x20];
    short id20;
    char pad22[0x8e84 - 0x22];
    int slot84[1];
};

struct Block_021eaa50 {
    unsigned short value;
    unsigned short prev;
    char pad4[5];
    unsigned char flag;
    char padA[6];
    Battle_021eaa50* battle;
};

struct Info_021eaa50 {
    char pad0[2];
    unsigned short value2;
    char pad4[0x3c - 4];
    unsigned char f3c;
};

struct Obj_021eaa50 {
    char pad0[0x138];
    Info_021eaa50* info;
    char pad13c[0x17c - 0x13c];
    unsigned char field17c;
};

struct Action_021eaa50 {
    char pad0[8];
    unsigned int f8 : 8;
    unsigned int p8 : 20;
    unsigned int f8_28 : 1;
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

struct Arr_021eaa50 {
    char pad[0xf6c];
    unsigned int f6c;
};

struct Tbl8_021eaa50 {
    unsigned short v[8];
};

extern Tbl8_021eaa50 data_ov024_021fe748;

extern "C" GameState* _ZN9GameState11GetInstanceEv();
extern "C" GameObject* _Z16GetCombatantByIDii(Battle_021eaa50*, int);
extern "C" GameObject* _Z29GetCombatantWithFlag0x400ByIDii(Battle_021eaa50*, int);
extern "C" int func_ov000_02153e78(Battle_021eaa50*, unsigned short*, int, unsigned char, int);
extern "C" int _Z28IsSpecialStateValue_02159c58Pvi(Battle_021eaa50*, int);
extern "C" int func_ov000_0215e9fc(Battle_021eaa50*, unsigned short*, int, int);
extern "C" unsigned int func_ov000_02159cb4(Battle_021eaa50*, int);
extern "C" int _Z32IsCombatantFlag2Mask512_021eadfcP10GameObject(Obj_021eaa50*);
extern "C" GameObject* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState*, int);
extern "C" unsigned int _Z22AdjustValueByFieldFlagPvj(GameObject*, unsigned int);
extern "C" int _Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010(Obj_021eaa50*);
extern "C" int _Z31IsIdOrEffectMatchTarget0215fd24ii(Battle_021eaa50*, int);
extern "C" Arr_021eaa50* _Z17GetPtrField0x2a04P9GameState(GameState*);
extern "C" GameObject* _Z26GetCombatantWithFlag0x1000P9GameStatei(GameState*, int);

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

extern "C" ARM int func_ov024_021eaa50(Block_021eaa50* a0, Block_021eaa50* sb,
                                                 Action_021eaa50* action, int flag4) {
    GameState* gs = _ZN9GameState11GetInstanceEv();
    short id = sb->battle->id20;
    Obj_021eaa50* self = (Obj_021eaa50*)_Z16GetCombatantByIDii(a0->battle, id);
    Tbl8_021eaa50 tbl = data_ov024_021fe748;

    if (sb->value == 0x153) {
        GameObject* c = _Z29GetCombatantWithFlag0x400ByIDii(a0->battle, sb->battle->id20);
        if (c == 0) {
            sb->value = 2;
            sb->flag = 0;
            return 2;
        }
        if (func_ov000_02153e78(a0->battle, tbl.v, 8, ((Obj_021eaa50*)c)->field17c, 1) != 8) {
            sb->value = 2;
            sb->flag = 0;
            return 2;
        }
    }
    if (sb->value == 0x31a) {
        GameObject* c = _Z29GetCombatantWithFlag0x400ByIDii(a0->battle, sb->battle->id20);
        if (c == 0) {
            sb->value = 2;
            sb->flag = 0;
            return 2;
        }
        if (func_ov000_02153e78(a0->battle, tbl.v, 8, ((Obj_021eaa50*)c)->field17c, 1) != 3) {
            sb->value = 2;
            sb->flag = 0;
            return 2;
        }
    }
    if (_Z28IsSpecialStateValue_02159c58Pvi(a0->battle, sb->value)) {
        if (func_ov000_0215e9fc(a0->battle, tbl.v, 8, 1) != 4) {
            sb->flag = 0;
            sb->value = (unsigned short)func_ov000_02159cb4(a0->battle, sb->battle->id20);
            return sb->value;
        }
    }

    int below = 0;
    if (!_Z32IsCombatantFlag2Mask512_021eadfcP10GameObject(self) && flag4 == 0 && !action->f8_28) {
        short v6 = (short)action->f8;
        if (IsPartyMember(id)) {
            v6 = (short)_Z22AdjustValueByFieldFlagPvj(
                _Z25GetCombatantWithFlag0x100P9GameStatei(gs, id), (unsigned int)v6);
        }
        if (action->f8 < 0xff) {
            if (self->info->value2 < v6) below = 1;
        } else {
            if (self->info->value2 == 0) below = 1;
        }
    }
    if (below) {
        int nv = 0x1f8;
        if (action->f18 == 1) nv = 0x3a9;
        unsigned short v = sb->value;
        sb->prev = v;
        sb->flag = 0;
        sb->value = nv;
        if (action->flags10 & 1) self->info->f3c |= 8;
        else self->info->f3c |= 0x20;
        return nv;
    }

    if ((action->flags10 & 1) && _Z22IsFlagBit8Set_021dd010P16FlagObj_021dd010(self)) {
        unsigned short v = sb->value;
        int nv = 0x392;
        sb->prev = v;
        sb->flag = 0;
        sb->value = nv;
        self->info->f3c |= 8;
        return nv;
    }

    if (action->f2c == 6 && IsPartyMember(id)) {
        int found = 0;
        if (_Z31IsIdOrEffectMatchTarget0215fd24ii(a0->battle, id)) {
            Arr_021eaa50* arr = _Z17GetPtrField0x2a04P9GameState(gs);
            if (arr->f6c < action->f32) found = 1;
        } else {
            GameObject* p = _Z26GetCombatantWithFlag0x1000P9GameStatei(gs, id);
            if (p != 0) {
                if (a0->battle->slot84[0] < action->f32) found = 1;
            } else {
                if (a0->battle->slot84[id] < action->f32) found = 1;
            }
        }
        if (found) {
            unsigned short v = sb->value;
            int nv = 0x3a7;
            sb->prev = v;
            sb->flag = 0;
            sb->value = nv;
            return nv;
        }
    }
    return sb->value;
}