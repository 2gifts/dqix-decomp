#include <globaldefs.h>

extern "C" unsigned char* func_0208e0a8(unsigned char* obj);

#if defined(jpn)
enum { FIELD_BYTE_OFFSET = 0xa7a };
#else
enum { FIELD_BYTE_OFFSET = 0xcda };
#endif

// USA: func_020120d4
ARM void SetByte0x5cdaAndClearField0xa(unsigned char* obj, unsigned char value) {
    unsigned char* p = obj + 0x5000;
    p[FIELD_BYTE_OFFSET] = value;
    unsigned char* r = func_0208e0a8(p);
    r[0xa] = 0;
}
