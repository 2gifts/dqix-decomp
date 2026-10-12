#include <globaldefs.h>

#if defined(jpn)
#define GetFieldAt0x1b8 func_0205504c
extern "C" ARM int func_0205504c(unsigned char* obj);
#endif

// USA: func_02053cd4
ARM int GetFieldAt0x1b8(unsigned char* obj) {
#if defined(jpn)
    enum { kFieldOffset = 0x1ac };
#else
    enum { kFieldOffset = 0x1b8 };
#endif
    return *(int*)(obj + kFieldOffset);
}
