#include <globaldefs.h>

#if defined(jpn)
enum { kHalfwordOffset = 0x3a };
#else
enum { kHalfwordOffset = 0x3c };
#endif


#if defined(jpn)
#define GetField3c_021fb234 func_ov023_021fa5d4
#endif

// USA: func_ov023_021fb234
#if defined(jpn)
extern "C"
#endif
ARM unsigned short GetField3c_021fb234(void* obj) {
    return *(unsigned short*)((char*)obj + kHalfwordOffset);
}
