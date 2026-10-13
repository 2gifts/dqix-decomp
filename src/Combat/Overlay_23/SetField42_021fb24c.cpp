#include <globaldefs.h>

#if defined(jpn)
enum { kHalfwordOffset = 0x40 };
#else
enum { kHalfwordOffset = 0x42 };
#endif

// USA: func_ov023_021fb24c
ARM void SetField42_021fb24c(void* obj, unsigned short v) {
    *(unsigned short*)((char*)obj + kHalfwordOffset) = v;
}
