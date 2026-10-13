#include <globaldefs.h>

// KEEP-NAME
// USA: func_02027bbc
// JPN: func_02027428
ARM void ClearFlags0xa97(unsigned char* base, int mask) {
#if defined(jpn)
    base[0x9cb] &= ~mask;
#else
    base[0xa97] &= ~mask;
#endif
}
