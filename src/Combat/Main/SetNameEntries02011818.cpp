#include <globaldefs.h>
#include "System/Memory.h"

struct Src02011818 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    char pad3;
    unsigned short f4;
    unsigned char f6;
    signed char f7;
    char pad8[0xb];
    signed char f0x13;
    char pad14[0xc];
    unsigned int f0x20;
    unsigned char f0x24;
    char pad25;
    unsigned short f0x26;
};

#if defined(jpn)
#define SetNameEntries02011818 func_02011588
extern "C" ARM void func_02011588(void* obj, struct Src02011818* src);
enum { kFieldOffsetDelta = 0x280, kNameOffsetDelta = 0x240 };
#else
enum { kFieldOffsetDelta = 0, kNameOffsetDelta = 0 };
#endif

// USA: func_02011818
ARM void SetNameEntries02011818(void* obj, struct Src02011818* src) {
    unsigned char* base = (unsigned char*)obj;
    base[0x646c - kFieldOffsetDelta] = 1;
    base[0x646d - kFieldOffsetDelta] = src->f6;
    base[0x6470 - kFieldOffsetDelta] = src->f0;
    if (src->f0 == 1) {
        base[0x6471 - kFieldOffsetDelta] = src->f1;
        *(unsigned short*)(base + (0x6472 - kFieldOffsetDelta)) = src->f4;
    } else {
        base[0x6471 - kFieldOffsetDelta] = src->f1;
        *(unsigned short*)(base + (0x6472 - kFieldOffsetDelta)) = src->f2;
        if (src->f0x26 != 0) *(unsigned short*)(base + (0x647e - kFieldOffsetDelta)) = src->f0x26;
    }
    if (src->f7 != 0) {
        VectorizedInvertedMemcpy(&src->f7, base + (0x64df - kNameOffsetDelta), 0xa);
    } else {
        base[0x64df - kNameOffsetDelta] = 0;
    }
    if (src->f0x13 != 0) {
        VectorizedInvertedMemcpy(&src->f0x13, base + (0x64e9 - kNameOffsetDelta), 0xa);
    } else {
        base[0x64e9 - kNameOffsetDelta] = 0;
    }
    if (src->f0x24 != 0) base[0x647c - kFieldOffsetDelta] = src->f0x24;
    *(unsigned int*)(base + (0x6478 - kFieldOffsetDelta)) = src->f0x20;
    *(int*)(base + (0x6474 - kFieldOffsetDelta)) = -1;
}
