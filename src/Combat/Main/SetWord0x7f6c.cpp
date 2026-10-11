#include <globaldefs.h>

// USA: func_02012010
ARM void SetWord0x7f6c(void* obj, int value) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    *(int*)(base + 0x7c98) = value;
#else
    *(int*)(base + 0x7f6c) = value;
#endif
}
