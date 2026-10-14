#include <globaldefs.h>

struct S_bc88;

// KEEP-NAME
// USA: func_0201bc88
ARM void SetField0x27da_0201bc88(S_bc88* obj, unsigned short value) {
#if defined(jpn)
    *(unsigned short*)((char*)obj + 0x281a) = value;
#else
    *(unsigned short*)((char*)obj + 0x27da) = value;
#endif
}
