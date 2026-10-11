#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x7014
#define REGION_OFFSET_1 0x701a
#define REGION_OFFSET_2 0x701b
#define REGION_OFFSET_3 0x701c
#else
#define REGION_OFFSET_0 0x6e24
#define REGION_OFFSET_1 0x6e2a
#define REGION_OFFSET_2 0x6e2b
#define REGION_OFFSET_3 0x6e2c
#endif


// USA: func_ov000_0216341c
ARM void SetFields0216341c(void* work, unsigned char b1, unsigned char b2, short h) {
    *(int*)((char*)work + REGION_OFFSET_0) = 1;
    *((unsigned char*)work + REGION_OFFSET_1) = b1;
    *((unsigned char*)work + REGION_OFFSET_2) = b2;
    *(short*)((char*)work + REGION_OFFSET_3) = h;
}
