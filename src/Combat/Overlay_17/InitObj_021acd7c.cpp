#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "System/Memory.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);
void InitBigStruct0205c790(char* obj);

#if defined(jpn)
#define TAIL_OFFSET 0x20c
#else
#define TAIL_OFFSET 0x27c
#endif

// USA: func_ov017_021acd7c  (semantic: InitObj_021acd7c)
extern "C" ARM void func_ov017_021acd7c(char* obj) {
    ResetByteHeader((struct ByteHeader0204693c*)obj);
    obj[0] = 1;
    ((SafeAllocator*)(obj + 0x8))->ResetAllocatorPointer();
    obj[0x1c] = 0;
    obj[0x1d] = 0;
    obj[TAIL_OFFSET + 0] = 0;
    obj[TAIL_OFFSET + 1] = 0;
    obj[TAIL_OFFSET + 2] = 0;
    obj[0x1e] = 0;
    obj[0x1f] = 0;
    obj[TAIL_OFFSET + 4] = 0;
    obj[TAIL_OFFSET + 3] = 0;
    *(short*)(obj + 0x40) = -1;
    obj[TAIL_OFFSET + 5] = 0;
    obj[TAIL_OFFSET + 6] = 0;
    *(int*)(obj + 0x20) = 0;
    *(int*)(obj + 0x24) = 0;
    *(int*)(obj + 0x28) = 0;
    VectorizedMemset(obj + 0x2c, 0, 0x14);
    InitBigStruct0205c790(obj + 0x44);
}
