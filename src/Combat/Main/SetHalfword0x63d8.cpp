#include <globaldefs.h>

// USA: func_020115f4
// JPN: func_02011364
ARM void SetHalfword0x63d8(void* obj, unsigned short value) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    *(unsigned short*)(base + 0x6178) = value;
#else
    *(unsigned short*)(base + 0x63d8) = value;
#endif
}
