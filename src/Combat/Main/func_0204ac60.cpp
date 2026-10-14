#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/VRAMStaging.h"

extern const VRAMSubregion data_020e7b60[];

// USA: func_0204ac60
extern "C" ARM void func_0204ac60(int unused, int index, char* obj) {
    int tmp;
    memcpy(&tmp, obj + 8, 4);
    StageMemoryToVRAM(data_020e7b60[index], obj + 0xc, 0, tmp, 1, 0);
}
