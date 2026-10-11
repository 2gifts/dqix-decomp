#include <globaldefs.h>

extern "C" void* func_ov000_0215e958(void* a0);
void AddEntryAndIncrementCount0215a88c(void* objRaw, void* listRaw, int c);
void AppendToChainAndIncCount0215ffc4(void* obj, void* node, int idx);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long ef, int g);

struct Obj_021e8cfc { char pad0c[0xc]; void* field0xc; void* field0x10; };

// USA: func_ov024_021e8cfc  (semantic: AddBuffEntryAndNotify_021e8cfc)
extern "C" ARM void* func_ov024_021e8cfc(struct Obj_021e8cfc* obj, void* c, int kind, int notifyExtra) {
    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return 0;
    if (notifyExtra) {
        AddEntryAndIncrementCount0215a88c(obj->field0x10, entry, 0xf1);
    }
    AddEntryAndIncrementCount0215a88c(obj->field0x10, entry, 0x25c);
    AppendToChainAndIncCount0215ffc4(obj->field0xc, entry, 1);
    ((unsigned char*)obj->field0x10)[0x8e02] = ((unsigned char*)obj->field0x10)[0x8e02] + 1;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    local.lo = 0;
    local.hi = 0;
    func_ov000_02159eac(obj->field0x10, &local, (unsigned char)kind);
    func_ov000_0215cd44(obj->field0x10, entry, c, 0, local.v, 0);
    return entry;
}
