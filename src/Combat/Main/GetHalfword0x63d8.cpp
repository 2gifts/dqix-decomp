#include <globaldefs.h>

// USA: func_020115e8
ARM unsigned short GetHalfword0x63d8_020115e8(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    return *(unsigned short*)(base + 0x6178);
#else
    return *(unsigned short*)(base + 0x63d8);
#endif
}
