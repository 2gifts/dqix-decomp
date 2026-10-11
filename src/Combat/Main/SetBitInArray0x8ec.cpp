#include <globaldefs.h>

// USA: func_02083acc
ARM void SetBitInArray0x8ec(unsigned char* obj, int index) {
#if defined(jpn)
    unsigned char* p = obj + 0x854;
#else
    unsigned char* p = obj + 0x8ec;
#endif
    p[index / 8] |= 1 << (index % 8);
}
