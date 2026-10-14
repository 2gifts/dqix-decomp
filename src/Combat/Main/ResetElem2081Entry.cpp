#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0204c804
ARM void ResetElem2081Entry_0204c804(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x9c) = 0;
    *(short*)(base + 0xac) = 0;
    *(short*)(base + 0xae) = 0;
    *(short*)(base + 0xa8) = 0;
    *(short*)(base + 0xaa) = 0;
    *(short*)(base + 0xb0) = 4;
    *(short*)(base + 0xb2) = 4;
    *(short*)(base + 0xb8) = 0;
    *(short*)(base + 0xba) = 0;
    *(short*)(base + 0xc0) = 0;
    base[0xc5] &= ~0x8;
    base[0xd8] &= ~0x1;
    base[0xd8] &= ~0x2;
#if !defined(jpn)
    base[0xd8] &= ~0x4;
#endif
    base[0xc4] = 0xff;
    base[0xc5] = 0;
    memset(base + 0xdb, 0, 4);
}
