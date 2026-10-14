#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"

extern const int data_020e7b68[];

// USA: func_0204ade8
extern "C" ARM void func_0204ade8(void* obj, int index, int y, unsigned char* ctx) {
    int tmp;
    memcpy((char*)obj + 8, ctx + 0xc, 4);
    tmp = *(int*)((char*)obj + 8);
    StageMemoryToVRAM((VRAMSubregion)(data_020e7b68[index] + y * 2), ctx + 0x10, 0, tmp, 1, 0);
}
