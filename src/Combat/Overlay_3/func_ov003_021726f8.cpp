#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue1C0_1CC = 0x1cc };
enum { kRegionValue128_134 = 0x134 };
enum { kRegionValue208_1E0 = 0x1e0 };
enum { kRegionValue12C_138 = 0x138 };
enum { kRegionValueD_C = 0xc };
enum { kRegionValue1AC_1B8 = 0x1b8 };
enum { kRegionValue2800_1C00 = 0x1c00 };
enum { kRegionValue184_190 = 0x190 };
enum { kRegionValue198_1A4 = 0x1a4 };
#else
enum { kRegionValue1C0_1CC = 0x1c0 };
enum { kRegionValue128_134 = 0x128 };
enum { kRegionValue208_1E0 = 0x208 };
enum { kRegionValue12C_138 = 0x12c };
enum { kRegionValueD_C = 0xd };
enum { kRegionValue1AC_1B8 = 0x1ac };
enum { kRegionValue2800_1C00 = 0x2800 };
enum { kRegionValue184_190 = 0x184 };
enum { kRegionValue198_1A4 = 0x198 };
#endif


struct Struct0205a198;
void Init0205a198(struct Struct0205a198* p);

struct ClearTarget0205a234;
void ClearField0And40205a234(struct ClearTarget0205a234* target);

// USA: func_ov003_021726f8
// JPN: func_ov003_021715e4
extern "C" ARM void func_ov003_021726f8(char* obj, SafeAllocator* allocator) {
    int i;

    if (allocator == 0) return;

    *(SafeAllocator**)(obj + kRegionValue1C0_1CC) = allocator;
    *(void**)(obj + kRegionValue128_134) = allocator->Allocate(kRegionValue208_1E0);
    *(void**)(obj + kRegionValue12C_138) = (*(SafeAllocator**)(obj + kRegionValue1C0_1CC))->Allocate(8);

    for (i = 0; i < kRegionValueD_C; i++) {
        Init0205a198((struct Struct0205a198*)(*(char**)(obj + kRegionValue128_134) + i * 0x28));
    }

    ClearField0And40205a234((struct ClearTarget0205a234*)*(void**)(obj + kRegionValue12C_138));

    void* p1 = (*(SafeAllocator**)(obj + kRegionValue1C0_1CC))->Allocate(0x1000);
    ((SafeAllocator*)(obj + kRegionValue1AC_1B8))->CreateTypeA(p1, 0x1000);
    ((SafeAllocator*)(obj + kRegionValue1AC_1B8))->Reset();

    void* p2 = (*(SafeAllocator**)(obj + kRegionValue1C0_1CC))->Allocate(kRegionValue2800_1C00);
    ((SafeAllocator*)(obj + kRegionValue184_190))->CreateTypeA(p2, kRegionValue2800_1C00);
    ((SafeAllocator*)(obj + kRegionValue184_190))->Reset();

    void* p3 = (*(SafeAllocator**)(obj + kRegionValue1C0_1CC))->Allocate(0x400);
    ((SafeAllocator*)(obj + kRegionValue198_1A4))->CreateTypeA(p3, 0x400);
    ((SafeAllocator*)(obj + kRegionValue198_1A4))->Reset();
}
