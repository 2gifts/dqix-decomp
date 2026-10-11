#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "System/Memory.h"

struct List0204af64;
ARM void ResetList0204af64(struct List0204af64* obj);

extern "C" ARM void func_0202445c(void* obj);

extern int data_020fdc4c;

// USA: func_02020720  (semantic: InitCombatObject_02020720)
extern "C" ARM void func_02020720(char* obj) {
    *(int*)(obj + 0x18) = 0;
    *(int*)(obj + 0x1c) = 0;
    *(int*)(obj + 0x20) = 0;
    *(int*)(obj + 0x24) = 0;
    *(int*)(obj + 0x28) = 0;
    *(int*)(obj + 0x2c) = 0;
    *(int*)(obj + 0x30) = 0;
    *(int*)(obj + 0x34) = 0;
    *(int*)(obj + 0x38) = 0x1000;
    int v = 0x1000 - 0x1400;
    *(int*)(obj + 0x3c) = v;
    *(int*)(obj + 0x40) = v;
    *(int*)(obj + 0x6c) = 0;
    *(int*)(obj + 0x70) = 0;
    *(int*)(obj + 0x74) = 0;
    *(int*)(obj + 0x14) = 1;
    *(unsigned char*)(obj + 0x55c) = 0;
    *(int*)(obj + (IS_JPN ? 0x6a8 : 0x754)) = 0;
    *(int*)(obj + 0x5a4) = *(int*)(obj + 0x5a4) & 1;
    *(unsigned char*)(obj + 0x0) = 0;
    *(int*)(obj + (IS_JPN ? 0x9d0 : 0xa9c)) = 0;

    for (int i = 0; i < 4; i++) {
        *(int*)(obj + 0x560 + i * 4) = -1;
        *(unsigned char*)(obj + 0x570 + i) = 0;
        *(unsigned char*)(obj + (IS_JPN ? 0x6ac : 0x758) + i) = 0;
        *(unsigned char*)(obj + 0x558 + i) = 1;
    }

    ResetList0204af64((struct List0204af64*)(obj + 0x4c));

    *(unsigned char*)(obj + (IS_JPN ? 0x6b0 : 0x75c)) = 0;
    *(unsigned char*)(obj + (IS_JPN ? 0x6b1 : 0x75d)) = 0;
    *(unsigned char*)(obj + (IS_JPN ? 0x6ce : 0x77a)) = 0;
    *(int*)(obj + (IS_JPN ? 0x6d0 : 0x77c)) = 0;
    *(int*)(obj + (IS_JPN ? 0x908 : 0x9b4)) = 0;
    *(int*)(obj + (IS_JPN ? 0x6b4 : 0x760)) = 0;
    *(unsigned char*)(obj + (IS_JPN ? 0x6b8 : 0x764)) = 0;
    *(short*)(obj + (IS_JPN ? 0x6ba : 0x766)) = 0;
    *(unsigned char*)(obj + (IS_JPN ? 0x6bc : 0x768)) = 1;

    func_0202445c(obj);

    *(int*)(obj + (IS_JPN ? 0x910 : 0x9bc)) = 0;
    *(unsigned char*)(obj + (IS_JPN ? 0x914 : 0x9c0)) = 0;
    *(int*)((char*)&data_020fdc4c + (IS_JPN ? 8 : 0xc)) = 0;
    *(short*)(obj + (IS_JPN ? 0x9d4 : 0xaa0)) = 0;

    VectorizedMemset(obj + (IS_JPN ? 0x9d6 : 0xaa2), 0, 0x100);
}
