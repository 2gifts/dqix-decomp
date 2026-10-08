#include <globaldefs.h>
#include "std_library_functions.h"

extern const int data_020e7b70[];

extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int a, int b, int c, int d, unsigned char e, unsigned char f);

// USA: func_0204a9c4
extern "C" ARM void func_0204a9c4(int* a0, int index, int y, char* ctx) {
    int tmp;
    if (ctx == NULL) return;
    memcpy(&tmp, ctx + 0xc, 4);
    _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(data_020e7b70[index] + y * 2, (int)(ctx + 0x10), *a0, tmp, 1, 0);
}
