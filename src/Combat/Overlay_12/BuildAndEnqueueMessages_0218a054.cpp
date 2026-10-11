#if defined(jpn)
#define R(j,u) (j)
#define func_ov012_021893b4 func_ov012_02189c90
#define func_ov012_0218a1f4 func_ov012_0218ae20
#define func_ov012_0218a2b8 func_ov012_0218ad7c
#define func_ov012_0218a374 func_ov012_0218acd8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov012_021893b4(void *self, int flags, int a, int b);
extern "C" void func_ov012_0218a2b8(void *self, void *dst, int c);
extern "C" void func_ov012_0218a1f4(void *self, void *dst, int c);
extern "C" void func_ov012_0218a374(void *self, void *dst, int c);
#if defined(jpn)
extern "C" void func_0205d304(void *a, void *b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void *a, void *b, int c, int d, int e, int f, int g, int h);
#endif
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(void *self, int a, int b);

// USA: func_ov012_0218a054  (semantic: BuildAndEnqueueMessages_0218a054)
extern "C" ARM void func_ov012_0218a054(char *self) {
    func_ov012_021893b4(self, 0x10, R(0x18,0x17), 0x15);
    memset(*(void **)(self + R(0x1344,0x1374)), 0, R(0x800,0x960));
#if defined(jpn)
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 0, 0, 1, 0);
#else
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 0, 0, 1, 0, 0);
#endif

    func_ov012_021893b4(self, 8, R(0xd,0xa), 8);
    memset(*(void **)(self + R(0x1344,0x1374)), 0, R(0x800,0x960));
    func_ov012_0218a2b8(self, *(void **)(self + R(0x1344,0x1374)), 0);
#if defined(jpn)
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0);
#else
#if defined(jpn)
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0);
#else
#if defined(jpn)
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0);
#else
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0, 0);
#endif
#endif
#endif

    func_ov012_021893b4(self, R(9,7), R(0x16,0x13), 8);
    memset(*(void **)(self + R(0x1344,0x1374)), 0, R(0x800,0x960));
    func_ov012_0218a1f4(self, *(void **)(self + R(0x1344,0x1374)), 0);
#if defined(jpn)
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0);
#else
#if defined(jpn)
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0);
#else
#if defined(jpn)
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0);
#else
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0, 0);
#endif
#endif
#endif

    func_ov012_021893b4(self, *(unsigned char *)(self + R(0x1341,0x1371)), 1, 8);
    memset(*(void **)(self + R(0x1344,0x1374)), 0, R(0x800,0x960));
    func_ov012_0218a374(self, *(void **)(self + R(0x1344,0x1374)), 0);
#if defined(jpn)
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0);
#else
#if defined(jpn)
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0);
#else
#if defined(jpn)
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0);
#else
    func_0205d304(self + R(0x90,0xac), *(void **)(self + R(0x1344,0x1374)), 0, 1, 0, 1, 0, 0);
#endif
#endif
#endif

    _Z17SetElementFieldC2P15Struct_0205d81cii(self + R(0x90,0xac), 0x10, 0);
}
