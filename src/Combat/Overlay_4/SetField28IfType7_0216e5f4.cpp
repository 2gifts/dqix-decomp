#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);
extern "C" void func_ov023_021f9ba8(void*, int);

// USA: func_ov004_0216e5f4  (semantic: SetField28IfType7_0216e5f4)
extern "C" ARM int func_ov004_0216e5f4(void* a) {
    void* obj = func_ov023_021f6880(func_ov011_021849c8(a), 0x12d);
    if (!obj) return 0;
    if (func_ov023_021f6f10(obj) != 7) return 0;
    func_ov023_021f9ba8(obj, 1);
    return 0;
}
