#include <globaldefs.h>

#if defined(jpn)
#define FIELD_OFFSET 0x40fe
#else
#define FIELD_OFFSET 0x431e
#endif

// JPN: func_ov017_021960e8
// USA: func_ov017_02195520
ARM void ClearByteField17182_02195520(void* obj) {
    *(unsigned char*)((char*)obj + FIELD_OFFSET) = 0;
}
