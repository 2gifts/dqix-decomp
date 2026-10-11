#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD 0x118
#else
#define REGION_FIELD 0x11c
#endif

// USA: func_ov017_021bbbf8
ARM void SetField11c_021bbbf8(void* obj, unsigned short v) {
    *(unsigned short*)((char*)obj + REGION_FIELD) = v;
}
