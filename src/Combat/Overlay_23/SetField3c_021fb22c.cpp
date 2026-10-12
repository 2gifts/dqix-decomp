#include <globaldefs.h>

#if defined(jpn)
enum { kHalfwordOffset = 0x3a };
#else
enum { kHalfwordOffset = 0x3c };
#endif


#if defined(jpn)
#define SetField3c_021fb22c func_ov023_021fa5cc
#endif

// USA: func_ov023_021fb22c
#if defined(jpn)
extern "C"
#endif
ARM void SetField3c_021fb22c(void* obj, unsigned short v) {
    *(unsigned short*)((char*)obj + kHalfwordOffset) = v;
}
