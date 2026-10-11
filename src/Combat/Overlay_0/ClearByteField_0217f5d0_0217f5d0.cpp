#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x485
#else
#define REGION_OFFSET_0 0x445
#endif


// USA: func_ov000_0217f5d0
ARM void ClearByteField_0217f5d0_0217f5d0(void* obj) {
    *(unsigned char*)((char*)obj + REGION_OFFSET_0) = 0;
}
