#include <globaldefs.h>
#include "System/Memory.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

struct Bits021a967c { unsigned short low14 : 14; unsigned short bit14 : 1; unsigned short bit15 : 1; };

// USA: func_ov017_021a967c  (semantic: InitObjAndClearFields_021a967c)
extern "C" ARM void func_ov017_021a967c(unsigned char* self, int id) {
    ResetByteHeader((struct ByteHeader0204693c*)self);
    self[0x0] = 0x3a;
    ((SafeAllocator*)(self + 0xc))->ResetAllocatorPointer();
    self[0x8] = 0;
    *(int*)(self + 0x20) = 0;
    self[0x24] = id;
    self[0x9] = 0;
    self[0x25] = 0;
    self[0x26] = 0;
    VectorizedMemset(self + 0x28, 0, 6);
    memset(self + 0x2e, 0, 0xb);
    ((Bits021a967c*)(self + 0x3a))->low14 = 0;
    self[0x39] = 0;
    ((Bits021a967c*)(self + 0x3a))->bit14 = 0;
    VectorizedMemset(self + 0x3c, 0, 0x18);
    *(int*)(self + 0x54) = 0;
}
