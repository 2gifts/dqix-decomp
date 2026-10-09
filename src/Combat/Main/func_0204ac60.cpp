#include <globaldefs.h>
#include "std_library_functions.h"

extern const int data_020e7b60[];

extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int a, int b, int c, int d, unsigned char e, unsigned char f);

// USA: func_0204ac60
extern "C" ARM int func_0204ac60(int unused, int index, char* obj) {
    int tmp;
    memcpy(&tmp, obj + 8, 4);
    return _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(data_020e7b60[index], (int)(obj + 0xc), 0, tmp, 1, 0);
}