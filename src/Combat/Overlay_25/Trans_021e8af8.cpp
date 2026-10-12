#include <globaldefs.h>

extern "C" unsigned int _Z26CopyInternalFields0207df50P11Foo0207df50(unsigned int);
extern "C" unsigned int _ZN13SafeAllocator4FreeEPv(unsigned int, unsigned int);
extern "C" unsigned int _ZN13SafeAllocator7DestroyEv(unsigned int, unsigned int);
extern "C" unsigned int _ZNK13SafeAllocator18GetSignedAllocatorEv(unsigned int);
extern "C" unsigned int func_ov025_021e8bc4(unsigned int, unsigned int);

// USA: func_ov025_021e8af8  (semantic: Trans_021e8af8)
extern "C" ARM unsigned int func_ov025_021e8af8(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int r4 = 0;
    unsigned int r5 = 0;
    r4 = r0;
    r1 = *(unsigned char*)((char*)r4 + 0x30);
    if (r1 == 0) { return r0; }
    r0 = (unsigned int)func_ov025_021e8bc4(r0, r1);
    r0 = *(unsigned char*)((char*)r4 + 0x30);
    r0 = r4 + (r0 << 2);
    r0 = *(unsigned int*)((char*)r0 + 0x10);
    r0 = (unsigned int)_ZNK13SafeAllocator18GetSignedAllocatorEv(r0);
    r1 = *(unsigned char*)((char*)r4 + 0x30);
    r5 = r0;
    r0 = r4 + (r1 << 2);
    r0 = *(unsigned int*)((char*)r0 + 0x10);
    r0 = (unsigned int)_ZN13SafeAllocator7DestroyEv(r0, r1);
    r0 = *(unsigned char*)((char*)r4 + 0x30);
    r1 = r5;
    r0 = r0 - 0x1;
    r0 = r4 + (r0 << 2);
    r0 = *(unsigned int*)((char*)r0 + 0x10);
    r0 = (unsigned int)_ZN13SafeAllocator4FreeEPv(r0, r1);
    r0 = *(unsigned char*)((char*)r4 + 0x30);
    r0 = r4 + (r0 << 2);
    r0 = *(unsigned int*)((char*)r0 + 0x20);
    r0 = (unsigned int)_Z26CopyInternalFields0207df50P11Foo0207df50(r0);
    r0 = *(unsigned char*)((char*)r4 + 0x30);
    r0 = r0 - 0x1;
    *(unsigned char*)((char*)r4 + 0x30) = (unsigned char)r0;
    return r0;
}
