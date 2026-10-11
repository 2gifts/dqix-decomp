#include <globaldefs.h>

#if defined(jpn)
#define FIELD_OFFSET 0x4111
#else
#define FIELD_OFFSET 0x4331
#endif

// USA: func_ov017_0218d500
ARM void ClearByteField17201_0218d500(void* obj) {
    *(unsigned char*)((char*)obj + FIELD_OFFSET) = 0;
}
