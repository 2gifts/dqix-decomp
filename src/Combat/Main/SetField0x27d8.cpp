#include <globaldefs.h>

struct S_bc7c;

// KEEP-NAME
// USA: func_0201bc7c
ARM void SetField0x27d8(S_bc7c* obj, unsigned short value) {
#if defined(jpn)
    *(unsigned short*)((char*)obj + 0x2818) = value;
#else
    *(unsigned short*)((char*)obj + 0x27d8) = value;
#endif
}
