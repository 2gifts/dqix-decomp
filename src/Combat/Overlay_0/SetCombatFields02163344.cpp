#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x5ab4
#define REGION_OFFSET_1 0x5abc
#define REGION_OFFSET_2 0x5ab8
#define REGION_OFFSET_3 0x5ab9
#define REGION_OFFSET_4 0x5aba
#define REGION_OFFSET_5 0x57e4
#else
#define REGION_OFFSET_0 0x58c4
#define REGION_OFFSET_1 0x58cc
#define REGION_OFFSET_2 0x58c8
#define REGION_OFFSET_3 0x58c9
#define REGION_OFFSET_4 0x58ca
#define REGION_OFFSET_5 0x55f4
#endif


// USA: func_ov000_02163344
ARM void SetCombatFields02163344(void* obj, int a1, short a2, unsigned char a3, unsigned short a4, unsigned short a5) {
    unsigned char* p = (unsigned char*)obj;
    *(int*)(p + REGION_OFFSET_0) = a1;
    *(short*)(p + REGION_OFFSET_1) = a2;
    p[REGION_OFFSET_2] = a3;
    p[REGION_OFFSET_3] = (unsigned char)a4;
    *(unsigned short*)(p + REGION_OFFSET_4) = a5;
    *(unsigned int*)(p + REGION_OFFSET_5) |= 0x2000;
}
