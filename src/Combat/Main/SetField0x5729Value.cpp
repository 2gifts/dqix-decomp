#include <globaldefs.h>

// USA: func_0201075c
ARM void SetField0x5729Value_0201075c(char* obj, unsigned char value) {
#if defined(jpn)
    *(unsigned char*)(obj + 0x54c9) = value;
#else
    *(unsigned char*)(obj + 0x5729) = value;
#endif
}
