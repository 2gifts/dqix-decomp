#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"

extern const int data_020e7b70[];

// USA: func_0204a9c4
extern "C" ARM void func_0204a9c4(int* a0, int index, int y, char* ctx) {
    int tmp;
    if (ctx == NULL) return;
    memcpy(&tmp, ctx + 0xc, 4);
    StageMemoryToVRAM((VRAMSubregion)(data_020e7b70[index] + y * 2), ctx + 0x10, *a0, tmp, true, false);
}
