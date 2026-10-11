#include <globaldefs.h>
#include "std_library_functions.h"

// JPN: func_ov025_021ed62c
// USA: func_ov025_021ed124
ARM void InitQueueStruct_021ed124(unsigned char* obj) {
    *(unsigned short*)(obj + 0x15e) = 0;
#if defined(jpn)
    *(unsigned short*)(obj + 0x1ac) = 0;
#else
    *(unsigned short*)(obj + 0x1ae) = 0;
#endif

    *(unsigned short*)(obj + 0x160) = 0;
    *(unsigned int*)(obj + 0x158) = 0;
    obj[0x150] = 0;
    obj[0x151] = 0;
    memset(obj, 0, 0x20);
    memset(obj + 0x20, 0, 0x20);
    memset(obj + 0x60, 0, 0x20);
    memset(obj + 0xa0, 0, 0x10);
    memset(obj + 0xb0, 0, 0x40);
    memset(obj + 0x40, 0, 0x20);
    memset(obj + 0xf0, 0, 0x40);
    memset(obj + 0x130, 0, 0x10);
    *(unsigned short*)(obj + 0x152) = 0;
    *(unsigned short*)(obj + 0x154) = 0;
    obj[0x16c] = 0;
#if !defined(jpn)
    *(unsigned short*)(obj + 0x1ac) = 0;
#endif
    *(unsigned short*)(obj + 0x162) = 0x2ee;
    *(unsigned short*)(obj + 0x15c) = 0;
}
