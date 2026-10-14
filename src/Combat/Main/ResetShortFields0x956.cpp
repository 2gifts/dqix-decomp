#include <globaldefs.h>

#if defined(jpn)
enum { kBase = 0x8be };
#else
enum { kBase = 0x956 };
#endif

// USA: func_020863a0
ARM void ResetShortFields0x956_020863a0(unsigned char* obj) {
    *(short*)(obj + kBase + 0) = 0;
    *(short*)(obj + kBase + 2) = -1;
    *(short*)(obj + kBase + 4) = 0;
    *(short*)(obj + kBase + 6) = 0;
    *(short*)(obj + kBase + 8) = -1;
}
