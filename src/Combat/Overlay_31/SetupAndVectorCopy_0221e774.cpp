#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_020ca390(int value, void* dst, int count);

// USA: func_ov031_0221e774  (semantic: SetupAndVectorCopy_0221e774)
extern "C" THUMB void func_ov031_0221e774(void* a0, char* a1) {
    func_020ca390(0, a1 + 0xc, 0x20);
    *(unsigned short*)(a1 + 0xa) = (unsigned short)*(int*)a0;
    VectorizedInvertedMemcpy((char*)a0 + 4, a1 + 0xc, *(unsigned short*)(a1 + 0xa));
}
