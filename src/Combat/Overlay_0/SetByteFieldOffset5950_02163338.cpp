#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xb40
#else
#define REGION_OFFSET_0 0x950
#endif


// USA: func_ov000_02163338
ARM void SetByteFieldOffset5950_02163338(unsigned char* obj, unsigned char val) {
    *(obj + 0x5000 + REGION_OFFSET_0) = val;
}
