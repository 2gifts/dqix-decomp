#include <globaldefs.h>
#include "System/Cache.h"

// USA: func_020d2a48
ARM void InitGridRowsAndFlushCache_020d2a48(void* p0) {
    int i, j, k;
    char* row;

    *(int*)((char*)p0 + 4) = 0;
    *(unsigned short*)((char*)p0 + 8) = 0;
    *(unsigned short*)((char*)p0 + 0xa) = 0;
    row = (char*)p0;
    *(int*)p0 = 0;

    i = 0;
    do {
        *(int*)(row + 0x40) = 0;
        j = 0;
        do {
            *(short*)(row + j * 2 + 0x20) = -1;
            j++;
        } while (j < 0x10);
        i++;
        row += 0x24;
    } while (i < 0x10);

    k = 0;
    do {
        *(short*)((char*)p0 + k * 2 + 0x200 + 0x60) = -1;
        k++;
    } while (k < 0x10);

    CleanInvalidateCacheRange(p0, 0x280);
}
