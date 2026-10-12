#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x1c2 };
#else
enum { FIELD_OFFSET = 0x1ce };
#endif

#if defined(jpn)
#define IsFlag0x1ceBit0x10Set func_02039840
extern "C" ARM unsigned int func_02039840(unsigned char* obj);
#endif

// USA: func_02039de8
ARM unsigned int IsFlag0x1ceBit0x10Set(unsigned char* obj) {
    return obj[FIELD_OFFSET] & 0x10;
}
