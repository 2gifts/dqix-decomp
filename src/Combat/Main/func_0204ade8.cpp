#include <globaldefs.h>
#include "std_library_functions.h"

extern const int data_020e7b68[];

extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int a, int b, int c, int d, unsigned char e, unsigned char f);

// USA: func_0204ade8
extern "C" ARM int func_0204ade8(void* obj, int index, int y, unsigned char* ctx) {
    int tmp;
    memcpy((char*)obj + 8, ctx + 0xc, 4);
    tmp = *(int*)((char*)obj + 8);
    return _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(data_020e7b68[index] + y * 2, (int)(ctx + 0x10), 0, tmp, 1, 0);
}