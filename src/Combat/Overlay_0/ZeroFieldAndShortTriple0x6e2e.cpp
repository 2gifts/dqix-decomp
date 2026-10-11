#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x701e
#define REGION_OFFSET_1 0x7020
#else
#define REGION_OFFSET_0 0x6e2e
#define REGION_OFFSET_1 0x6e30
#endif


// USA: func_ov000_02163b60
ARM void ZeroFieldAndShortTriple0x6e2e(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    p[REGION_OFFSET_0] = 0;
    for (int i = 0; i < 3; i++) *(unsigned short*)(p + REGION_OFFSET_1 + i * 2) = 0;
}
