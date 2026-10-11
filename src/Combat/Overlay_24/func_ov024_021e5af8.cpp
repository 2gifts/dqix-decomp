#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a004(void* a0, int id1, int id2, int flags, void* buf, int extra, int zero, int sixteen);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);
void AppendToChainAndIncCount0215fe84(void* obj, void* node, int idx);

struct Obj_021e5af8 { char pad0[8]; void* field0x8; char pad1[4]; void* field0x10; };

// USA: func_ov024_021e5af8
extern "C" ARM void func_ov024_021e5af8(struct Obj_021e5af8* obj, int id, int extra) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return;
    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    local.lo = 0;
    local.hi = 0;
    func_ov000_0215a004(obj->field0x10, id, id, 0xffff, &local, extra, 0, 0x10);
    local.lo = 0;
    local.hi = 0;
    func_ov000_02159eac(obj->field0x10, &local, 13);
    AddEntryAndIncrementCount0215a88c(obj->field0x10, entry, 0x117);
    func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, 0);
    AppendToChainAndIncCount0215fe84(obj->field0x8, entry, 2);
    ((unsigned char*)obj->field0x10)[0x8e02]++;
}
