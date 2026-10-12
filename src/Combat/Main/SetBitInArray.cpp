#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x5a70 };
#else
enum { FIELD_OFFSET = 0x5cd0 };
#endif

#if defined(jpn)
#define SetBitInArray func_02011118
extern "C" ARM void func_02011118(void* obj, int a, int b);
#endif

// USA: func_020113a8
ARM void SetBitInArray(void* obj, int a, int b) {
    unsigned int n = (a - 1) * 5 + b;
    unsigned int byte = n >> 3;
    unsigned char* p = (unsigned char*)obj + FIELD_OFFSET;
    p[byte] |= (unsigned char)(1 << (n - (byte << 3)));
}
