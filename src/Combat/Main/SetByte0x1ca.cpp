#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x1be };
#else
enum { FIELD_OFFSET = 0x1ca };
#endif

// USA: func_02039880
ARM void SetByte0x1ca_02039880(unsigned char* obj, int value) {
    obj[FIELD_OFFSET] = value;
}
