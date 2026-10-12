#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x248 };
#else
enum { FIELD_OFFSET = 0x254 };
#endif

#if defined(jpn)
#define GetByteField0x254 func_020392a8
extern "C" ARM unsigned char func_020392a8(void* obj);
#endif

// USA: func_02039850
ARM unsigned char GetByteField0x254(void* obj) {
    return *((unsigned char*)obj + FIELD_OFFSET);
}
