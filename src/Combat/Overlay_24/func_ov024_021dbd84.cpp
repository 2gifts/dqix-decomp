#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

int CheckField0x14Flags0x9Clear(unsigned char* obj);
extern "C" void _Z24ResetStateFields02088338Ph(unsigned char* obj);
struct Ctx_021e929c;
extern "C" int _Z29SelectMessageByFlags_021e929cP12Ctx_021e929cii(struct Ctx_021e929c* ctx, int id, int flag);
struct FlagObj_021da998;
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(struct FlagObj_021da998* obj);
extern "C" int _Z26IsFlagAllowedMask_021eb4b0iii(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void* func_ov024_021e8cfc(void* obj, void* c, int kind, int notifyExtra);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* unused0, void* obj, unsigned short* sel);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct PackedPair_021dbd84 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Flag_021dbd84 { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021dbd84 {
    char pad0[0xc];
    void* field0xc;
    void* field0x10;
    int field0x14;
    char pad18[0x75 - 0x18];
    unsigned char byte0x75;
};
struct Field4Bits_021dbd84 { unsigned int low12 : 12; unsigned int rest : 20; };
struct Range_021dbd84 {
    char pad0[4];
    struct Field4Bits_021dbd84 field4;
    char pad1[0x20 - 8];
    struct PackedPair_021dbd84 f20;
    struct PackedPair_021dbd84 f24;
};
struct StatsFlags_021dbd84 { char pad[0x14]; int flags; };

// USA: func_ov024_021dbd84
extern "C" ARM void* func_ov024_021dbd84(struct Obj_021dbd84* obj, int unused, int id, struct Range_021dbd84* range, int unused2, int unused3, unsigned char flagArg) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return 0;
    int special = 0;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    int clear = CheckField0x14Flags0x9Clear((unsigned char*)c->currentStats_);
    if (clear && flagArg) special = 1;
    local.lo = 0;
    local.hi = 0;
    unsigned short sel = _Z29SelectMessageByFlags_021e929cP12Ctx_021e929cii((struct Ctx_021e929c*)obj, id, special);
    int flagA = _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998((struct FlagObj_021da998*)c);
    if (special) {
        if (range->field4.low12 == 0x233) sel = range->f20.c;
        if (_Z26IsFlagAllowedMask_021eb4b0iii((int)obj, ((struct StatsFlags_021dbd84*)c->currentStats_)->flags, 0x10)) {
            func_ov000_02159eac(obj->field0x10, &local, 0x2b);
        }
        _Z24ResetStateFields02088338Ph((unsigned char*)c->currentStats_);
        func_ov000_02159eac(obj->field0x10, &local, 0xe);
        obj->field0x14++;
        if (flagA) func_ov024_021e8cfc(obj, c, 0, 0);
    } else {
        obj->byte0x75 = 0;
    }
    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return 0;
    func_ov024_021e8bf0(obj, obj->field0xc, &sel);
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
    struct Flag_021dbd84* fl = (struct Flag_021dbd84*)((char*)obj->field0xc + 0x1c);
    func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, fl->flag != 0);
    return entry;
}
