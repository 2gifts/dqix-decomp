#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x248 };
#else
enum { FIELD_OFFSET = 0x254 };
#endif

// USA: func_02039850
ARM unsigned char GetByteField0x254_02039850(void* obj) {
    return *((unsigned char*)obj + FIELD_OFFSET);
}
