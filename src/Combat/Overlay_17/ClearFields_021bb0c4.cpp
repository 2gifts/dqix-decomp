#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
static const int kShift=4;
#else
static const int kShift=0;
#endif

// USA: func_ov017_021bb0c4
ARM void ClearFields_021bb0c4(unsigned char* obj) {
    obj[0xfc - kShift] = 0;
    *(unsigned short*)(obj + 0x11a - kShift) = 0;
    memset(obj + 0x13c - kShift, 0, 0x12);
    memset(obj + 0x150 - kShift, 0, 0xa);
    *(int*)(obj + 0x15c - kShift) = 0;
    obj[0xfe - kShift] = 0;
}
