#include <globaldefs.h>

extern "C" void func_020e53bc(void* a, int b, void* c, void* d);
struct Pair020e5204;
void RemapBothPointerFields(void*, struct Pair020e5204*);

// USA: func_020e56fc
ARM int TryInvoke020e53bc_020e56fc(void* a0, int a1, int a2) {
    int local;
    if (a1 == 0 || a2 == 0) return 0;
    func_020e53bc(a0, a1, &local, (void*)RemapBothPointerFields);
    return 1;
}
