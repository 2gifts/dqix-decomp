#include <globaldefs.h>

#if defined(jpn)
enum { X_OFFSET = 0x4c, Y_OFFSET = 0x4e };
#else
enum { X_OFFSET = 0x50, Y_OFFSET = 0x52 };
#endif


#if defined(jpn)
#define GetFixed12PairAndZero_021f7d48 func_ov023_021f7240
#endif

struct Triple_021f7d48 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

// USA: func_ov023_021f7d48
#if defined(jpn)
extern "C"
#endif
ARM struct Triple_021f7d48 GetFixed12PairAndZero_021f7d48(void* src) {
    struct Triple_021f7d48 t;
    short a = *(short*)((char*)src + X_OFFSET);
    short b = *(short*)((char*)src + Y_OFFSET);
    t.a = a << 0xc;
    t.b = b << 0xc;
    t.c = 0;
    return t;
}
