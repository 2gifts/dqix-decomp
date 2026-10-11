#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x948
#define REGION_OFFSET_1 0x95c
#define REGION_OFFSET_2 0x7e4
#else
#define REGION_OFFSET_0 0x758
#define REGION_OFFSET_1 0x76c
#define REGION_OFFSET_2 0x5f4
#endif


// USA: func_ov000_02163378
ARM void CopyFourAndSetFlag02163378(void* dst, int* src, unsigned char val) {
    int i;
    for (i = 0; i < 4; i++) {
        *(int*)((char*)dst + i * 4 + 0x5000 + REGION_OFFSET_0) = src[i];
    }
    *((unsigned char*)dst + 0x5000 + REGION_OFFSET_1) = val;
    *(int*)((char*)dst + 0x5000 + REGION_OFFSET_2) |= 0x4000;
}
