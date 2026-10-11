#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);
int GetGlobalField0x1c020421a0();

// JPN: 021b5db0
// USA: func_ov017_021b57fc  (semantic: InitStateAndConfigDisplay_021b57fc)
extern "C" ARM void func_ov017_021b57fc(unsigned char* obj) {
    ResetByteHeader((struct ByteHeader0204693c*)obj);

    obj[0x0] = 0x15;
    *(int*)(obj + 0x8) = 0;
    obj[0xc] = 0;
    *(unsigned short*)(obj + 0x10) = 0xffff;
    *(int*)(obj + 0x1c) = 0;
    *(short*)(obj + 0xe) = 0;
    *(int*)(obj + 0x20) = 0;
    *(int*)(obj + 0x24) = 0;
    *(int*)(obj + 0x28) = -1;
    *(unsigned short*)(obj + 0x12) = 0xffff;
    obj[0x16] = 0x3d;
    *(int*)(obj + 0x38) = 0;
    obj[0x17] = 0;
    *(short*)(obj + 0x14) = -1;
    *(short*)(obj + 0x18) = 0x1f4;

    ((SafeAllocator*)(obj + 0x40))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x58))->ResetAllocatorPointer();

    int field = GetGlobalField0x1c020421a0();
#if defined(jpn)
    void* p = *(void**)((char*)field + 0x28);
    memset(*(void**)(obj + 0x3c) = p, 0, 0x800);
#else
    void* p = *(void**)((char*)field + 0x5c);
    memset(*(void**)(obj + 0x3c) = p, 0, 0x960);
#endif

    unsigned int f = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
    f |= 0x10;
    unsigned int cleared = *(volatile unsigned int*)0x4000000 & ~0x1f00;
    *(volatile unsigned int*)0x4000000 = cleared | (f << 8);

    obj[0x54] = 0;
}
