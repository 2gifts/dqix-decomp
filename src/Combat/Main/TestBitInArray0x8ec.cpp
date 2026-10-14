#include <globaldefs.h>

// USA: func_02083b00
ARM int TestBitInArray0x8ec_02083b00(unsigned char* obj, int index) {
    unsigned char* p = obj + index / 8;
#if defined(jpn)
    return (1 << (index % 8)) & p[0x854];
#else
    return (1 << (index % 8)) & p[0x8ec];
#endif
}
