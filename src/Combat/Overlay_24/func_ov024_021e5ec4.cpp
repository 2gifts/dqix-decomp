#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int _Z36CheckField0x14FiveFlagsClear020881c4Ph(unsigned char* obj);
void ResetAndSetFlag0x1000000(void* obj);
extern "C" void _Z26SetFlag0x800000AndByte0x24Pvh(void* obj, int level);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);
extern "C" void _Z32AppendToChainAndIncCount0215fe84PvS_i(void* obj, void* node, int idx);

struct Chain_021e5ec4 { char pad0[0x2d]; unsigned char byte0x2d; };
struct Obj_021e5ec4 { char pad0[8]; struct Chain_021e5ec4* field0x8; char pad1[4]; unsigned char* field0x10; };
struct Stats_021e5ec4 { char pad0[0x24]; unsigned char level; };

// USA: func_ov024_021e5ec4
extern "C" ARM void func_ov024_021e5ec4(struct Obj_021e5ec4* obj, int id) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return;
    if (!_Z36CheckField0x14FiveFlagsClear020881c4Ph((unsigned char*)c->currentStats_)) return;

    int level;
    int msg = 0;
    level = ((struct Stats_021e5ec4*)c->currentStats_)->level;
    switch (level + 1) {
    case 1: msg = 0x31; break;
    case 2: msg = 0x32; break;
    case 3: msg = 0x33; break;
    case 4: msg = 0x34; break;
    }

    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    local.lo = 0;
    local.hi = 0;
    if (level + 1 >= 4) {
        ResetAndSetFlag0x1000000(c->currentStats_);
        func_ov000_02159eac(obj->field0x10, &local, 7);
        func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, 0);
        _Z32AppendToChainAndIncCount0215fe84PvS_i(obj->field0x8, entry, 2);
        obj->field0x10[0x8e02]++;
        obj->field0x8->byte0x2d = 1;
    } else {
        _Z26SetFlag0x800000AndByte0x24Pvh(c->currentStats_, level + 1);
        func_ov000_02159eac(obj->field0x10, &local, 0x23);
        func_ov000_0215cd44(obj->field0x10, entry, c, (short)(level + 1), local.v, 0);
        _Z32AppendToChainAndIncCount0215fe84PvS_i(obj->field0x8, entry, 2);
        obj->field0x10[0x8e02]++;
    }
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, (unsigned short)msg);
}
