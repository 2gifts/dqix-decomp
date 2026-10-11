#include <globaldefs.h>

#if defined(jpn)
static const int kCount=0x2498, kStride=0x8e0;
#else
static const int kCount=0x2788, kStride=0x99c;
#endif

// USA: func_ov023_021f0360
ARM void* FindByByteAt118_021f0360(void* base, int val) {
    unsigned char* p = (unsigned char*)base + 0x118;
    int i;
    for (i = 0; i < *((unsigned char*)base + kCount); i++) {
        if (*p == val) {
            return p;
        }
        p += kStride;
    }
    return 0;
}
