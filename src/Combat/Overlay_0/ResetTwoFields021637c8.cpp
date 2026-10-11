#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x792c
#define REGION_OFFSET_1 0x7930
#else
#define REGION_OFFSET_0 0x773c
#define REGION_OFFSET_1 0x7740
#endif

#include "std_library_functions.h"

// USA: func_ov000_021637c8
ARM void ResetTwoFields021637c8(void* obj) {
    memset((char*)obj + REGION_OFFSET_0, -1, 4);
    memset((char*)obj + REGION_OFFSET_1, 0, 4);
}
