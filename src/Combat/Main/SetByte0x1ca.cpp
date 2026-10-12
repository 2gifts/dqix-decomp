#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x1be };
#else
enum { FIELD_OFFSET = 0x1ca };
#endif

#if defined(jpn)
#define SetByte0x1ca func_020392d8
extern "C" ARM void func_020392d8(unsigned char* obj, unsigned char value);
#endif

// USA: func_02039880
ARM void SetByte0x1ca(unsigned char* obj, unsigned char value) {
    obj[FIELD_OFFSET] = value;
}
