#include <globaldefs.h>

// USA: func_02011634
ARM void ClearHalfword0x63da(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    *(unsigned short*)(base + 0x617a) = 0;
#else
    *(unsigned short*)(base + 0x63da) = 0;
#endif
}
