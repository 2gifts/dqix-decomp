#include <globaldefs.h>

#if defined(jpn)
enum { kHalfwordOffset = 0x40 };
#else
enum { kHalfwordOffset = 0x42 };
#endif

// USA: func_ov023_021fb254
ARM unsigned short GetField42_021fb254(void* obj) {
    return *(unsigned short*)((char*)obj + kHalfwordOffset);
}
