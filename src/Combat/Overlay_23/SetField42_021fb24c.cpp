#include <globaldefs.h>

#if defined(jpn)
enum { kHalfwordOffset = 0x40 };
#else
enum { kHalfwordOffset = 0x42 };
#endif


#if defined(jpn)
#define SetField42_021fb24c func_ov023_021fa5ec
#endif

// USA: func_ov023_021fb24c
#if defined(jpn)
extern "C"
#endif
ARM void SetField42_021fb24c(void* obj, unsigned short v) {
    *(unsigned short*)((char*)obj + kHalfwordOffset) = v;
}
