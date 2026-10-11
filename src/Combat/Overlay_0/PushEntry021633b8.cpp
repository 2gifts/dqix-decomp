#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x5af0
#define REGION_OFFSET_1 0x5ac0
#else
#define REGION_OFFSET_0 0x5900
#define REGION_OFFSET_1 0x58d0
#endif


struct Entry021633b8 { unsigned short f0; unsigned short f2; unsigned char f4; signed char f5; };

// USA: func_ov000_021633b8
ARM void PushEntry021633b8(char* obj, struct Entry021633b8* src) {
    unsigned char* countPtr = (unsigned char*)(obj + REGION_OFFSET_0);
    unsigned char idx = (*countPtr)++;
    struct Entry021633b8* dest = (struct Entry021633b8*)(obj + REGION_OFFSET_1) + idx;
    dest->f0 = src->f0;
    dest->f2 = src->f2;
    dest->f4 = src->f4;
    dest->f5 = src->f5;
}
