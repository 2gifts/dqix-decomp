#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue228_110 = 0x110 };
enum { kRegionValue23C_124 = 0x124 };
enum { kRegionValue264_14C = 0x14c };
enum { kRegionValue278_160 = 0x160 };
enum { kRegionValue28C_174 = 0x174 };
enum { kRegionValue2A0_188 = 0x188 };
enum { kRegionValue2B4_19C = 0x19c };
enum { kRegionValue2C8_1B0 = 0x1b0 };
#else
enum { kRegionValue228_110 = 0x228 };
enum { kRegionValue23C_124 = 0x23c };
enum { kRegionValue264_14C = 0x264 };
enum { kRegionValue278_160 = 0x278 };
enum { kRegionValue28C_174 = 0x28c };
enum { kRegionValue2A0_188 = 0x2a0 };
enum { kRegionValue2B4_19C = 0x2b4 };
enum { kRegionValue2C8_1B0 = 0x2c8 };
#endif


// USA: func_ov003_0215f8cc
// JPN: func_ov003_0215fa80
extern "C" ARM void func_ov003_0215f8cc(void* self, SafeAllocator* other) {
    if (other == 0) return;

    void* buf = other->Allocate(0x1000);
    ((SafeAllocator*)((char*)self + kRegionValue228_110))->CreateTypeA(buf, 0x1000);

    buf = other->Allocate(0x7000);
    ((SafeAllocator*)((char*)self + kRegionValue23C_124))->CreateTypeA(buf, 0x7000);

    buf = other->Allocate(0x2000);
    ((SafeAllocator*)((char*)self + kRegionValue264_14C))->CreateTypeA(buf, 0x2000);

    buf = other->Allocate(0x7400);
    ((SafeAllocator*)((char*)self + kRegionValue278_160))->CreateTypeA(buf, 0x7400);

    buf = other->Allocate(0x4c00);
    ((SafeAllocator*)((char*)self + kRegionValue28C_174))->CreateTypeA(buf, 0x4c00);

    buf = other->Allocate(0xc00);
    ((SafeAllocator*)((char*)self + kRegionValue2A0_188))->CreateTypeA(buf, 0xc00);

    buf = other->Allocate(0x3c00);
    ((SafeAllocator*)((char*)self + kRegionValue2B4_19C))->CreateTypeA(buf, 0x3c00);

    buf = other->Allocate(0x200);
    ((SafeAllocator*)((char*)self + kRegionValue2C8_1B0))->CreateTypeA(buf, 0x200);
}
