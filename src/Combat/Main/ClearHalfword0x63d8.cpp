#include <globaldefs.h>

// USA: func_02011600
// JPN: func_02011370
ARM void ClearHalfword0x63d8(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    *(unsigned short*)(base + 0x6178) = 0;
#else
    *(unsigned short*)(base + 0x63d8) = 0;
#endif
}
