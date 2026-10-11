#include <globaldefs.h>

// USA: func_02042b1c
ARM void InitSelfPointer(unsigned char* base) {
#if defined(jpn)
    *(unsigned char**)(base + 0x1c44) = base + 0x7e4;
#else
    *(unsigned char**)(base + 0x1e20) = base + 0x914;
#endif
}
