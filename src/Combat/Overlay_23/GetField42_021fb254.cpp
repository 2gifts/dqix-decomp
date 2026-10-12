#include <globaldefs.h>

#if defined(jpn)
enum { kHalfwordOffset = 0x40 };
#else
enum { kHalfwordOffset = 0x42 };
#endif


#if defined(jpn)
#define GetField42_021fb254 func_ov023_021fa5f4
#endif

// USA: func_ov023_021fb254
#if defined(jpn)
extern "C"
#endif
ARM unsigned short GetField42_021fb254(void* obj) {
    return *(unsigned short*)((char*)obj + kHalfwordOffset);
}
