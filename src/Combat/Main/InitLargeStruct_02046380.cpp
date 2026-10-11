#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02046380  (semantic: InitLargeStruct_02046380)
extern "C" ARM void func_02046380(void* obj) {
#if defined(jpn)
    *(signed char*)((char*)obj + 0x1750) = -1;
    memset((char*)obj + 0x23c, 0, 0x40);
    memset((char*)obj + 0x27c, 0, 0x40);
    memset((char*)obj + 0x2bc, 0, 0x40);
    memset((char*)obj + 0x2fc, 0, 0x40);
    memset((char*)obj + 0x33c, 0, 0x40);
    memset((char*)obj + 0x37c, 0, 0x400);
    memset((char*)obj + 0x780, 0, 0x40);
    memset((char*)obj + 0x7c1, 0, 0x10);
    memset((char*)obj + 0x7d2, 0, 0x10);
    *(int*)((char*)obj + 0x77c) = 0;
    *(unsigned char*)((char*)obj + 0x7d1) = 0;
    *(unsigned char*)((char*)obj + 0x7c0) = 0;
    *(int*)((char*)obj + 0x238) = 0;
#else
    *(signed char*)((char*)obj + 0x30) = -1;
    *(signed char*)((char*)obj + 0x31) = -1;
    *(signed char*)((char*)obj + 0x1880) = -1;
    memset((char*)obj + 0x2ec, 0, 0xc0);
    memset((char*)obj + 0x3ac, 0, 0x40);
    memset((char*)obj + 0x3ec, 0, 0x40);
    memset((char*)obj + 0x42c, 0, 0x40);
    memset((char*)obj + 0x46c, 0, 0x40);
    memset((char*)obj + 0x4ac, 0, 0x400);
    memset((char*)obj + 0x8b0, 0, 0x40);
    memset((char*)obj + 0x8f1, 0, 0x10);
    memset((char*)obj + 0x902, 0, 0x10);

    *(int*)((char*)obj + 0x8ac) = 0;
    *(unsigned char*)((char*)obj + 0x901) = 0;
    *(unsigned char*)((char*)obj + 0x8f0) = 0;
    *(int*)((char*)obj + 0x2e8) = 0;

    int (*matrix)[2] = (int(*)[2])obj;
    for (int i = 0; i < 2; i++) {
        matrix[0][i] = 0;
        matrix[1][i] = 0;
        matrix[2][i] = 0;
        matrix[3][i] = 0;
        matrix[4][i] = 0;
    }

    *(int*)((char*)obj + 0x28) = 0;
    *(int*)((char*)obj + 0x2c) = 0;
    *(unsigned char*)((char*)obj + 0x19d5) = 0;
    *(unsigned char*)((char*)obj + 0x19d6) = 0;
    *(unsigned char*)((char*)obj + 0x19d7) = 0;
    *(unsigned char*)((char*)obj + 0x19d8) = 0;
#endif
}
