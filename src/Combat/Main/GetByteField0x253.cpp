#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x247 };
#else
enum { FIELD_OFFSET = 0x253 };
#endif

#if defined(jpn)
#define GetByteField0x253 func_02039280
extern "C" ARM unsigned char func_02039280(void* obj);
#endif

// USA: func_02039828
ARM unsigned char GetByteField0x253(void* obj) {
    return *((unsigned char*)obj + FIELD_OFFSET);
}
