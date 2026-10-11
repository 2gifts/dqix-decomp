#if defined(jpn)
#define R(j,u) (j)
#define func_ov023_021f6524 func_ov004_02168f08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov023_021f6524(void* ctx, int value);
extern "C" void func_ov023_021f9ba8(void* obj, unsigned short v);

// USA: func_ov004_021694e8  (semantic: SetFieldOnType7Node_021694e8)
extern "C" ARM int func_ov004_021694e8(void* a1) {
    void* obj = func_ov023_021f6524(a1, 0x65);
    if (obj != 0) {
        func_ov023_021f9ba8(obj, 1);
    }
    return 0;
}
