#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct PackedPair_021dd534 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Range_021dd534 {
    char pad[0x20];
    struct PackedPair_021dd534 f20;
    struct PackedPair_021dd534 f24;
    char pad28[8];
    short code;
};

struct Bits_021dd534 { unsigned short low6 : 6; unsigned short code : 3; unsigned short rest : 7; };

struct Stats_021dd534 {
    char pad0[0x14];
    int flags;
    char pad18[0xa];
    struct Bits_021dd534 f22;
};

struct Flag_021dd534 { unsigned char pad : 7; unsigned char flag : 1; };

struct Obj_021dd534 {
    char pad0[0xc];
    void* fc;
    void* f10;
    char pad14[0x61];
    unsigned char f75;
};

extern "C" int _Z31CheckField0x14Bit0Clear02088840Ph(unsigned char* obj);
void SetFlag0x40AndBytes(unsigned char* obj);
extern "C" int func_ov024_021e9198(struct Obj_021dd534* ctx, int id, short code, int mode);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" int _Z26IsFlagAllowedMask_021eb4b0iii(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* world, unsigned long long* bits, int bit);
extern "C" void* func_ov000_0215e958(void* world);
extern "C" void func_ov024_021e8bf0(struct Obj_021dd534* obj, void* fieldC, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* world, void* entry, int msg);
extern "C" void func_ov000_0215cd44(void* world, void* entry, GameObject* c, int d, unsigned long long bits, int flag);

// USA: func_ov024_021dd534
extern "C" ARM void* func_ov024_021dd534(struct Obj_021dd534* obj, int unused, int id, struct Range_021dd534* range, int unused2, int unused3, unsigned char flagArg) {
    GameObject* c = GetCombatantByID((int)obj->f10, id);
    if (!c) return 0;
    unsigned short sel = 0;
    unsigned long long bits = 0;
    int code = range->code;
    if (_Z31CheckField0x14Bit0Clear02088840Ph((unsigned char*)c->currentStats_) && flagArg) {
        sel = func_ov024_021e9198(obj, id, code, 1);
        if (sel == 0) {
            sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f20.c, range->f24.a);
        }
        if (_Z26IsFlagAllowedMask_021eb4b0iii((int)obj, ((struct Stats_021dd534*)c->currentStats_)->flags, 0x40)) {
            func_ov000_02159eac(obj->f10, &bits, 0x2b);
        }
        SetFlag0x40AndBytes((unsigned char*)c->currentStats_);
        ((struct Stats_021dd534*)c->currentStats_)->f22.code = (unsigned char)code;
    } else {
        sel = func_ov024_021e9198(obj, id, code, 0);
        if (sel == 0) {
            sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
        }
        obj->f75 = 0;
    }
    void* entry = func_ov000_0215e958(obj->f10);
    if (!entry) return 0;
    func_ov024_021e8bf0(obj, obj->fc, &sel);
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->f10, entry, sel);
    struct Flag_021dd534* fl = (struct Flag_021dd534*)((char*)obj->fc + 0x1c);
    func_ov000_0215cd44(obj->f10, entry, c, 0, bits, fl->flag != 0);
    return entry;
}
