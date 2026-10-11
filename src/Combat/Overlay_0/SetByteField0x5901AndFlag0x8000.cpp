#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x5af1
#define REGION_OFFSET_1 0x57e4
#else
#define REGION_OFFSET_0 0x5901
#define REGION_OFFSET_1 0x55f4
#endif


// USA: func_ov000_02163404
ARM void SetByteField0x5901AndFlag0x8000(void* work, unsigned char val) {
    *(unsigned char*)((char*)work + REGION_OFFSET_0) = val;
    *(int*)((char*)work + REGION_OFFSET_1) |= 0x8000;
}
