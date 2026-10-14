#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x247 };
#else
enum { FIELD_OFFSET = 0x253 };
#endif

// USA: func_02039828
ARM unsigned char GetByteField0x253_02039828(void* obj) {
    return *((unsigned char*)obj + FIELD_OFFSET);
}
