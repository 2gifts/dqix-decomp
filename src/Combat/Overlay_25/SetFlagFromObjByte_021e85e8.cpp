#include <globaldefs.h>

#if defined(jpn)
enum { kWorldFlagOffset = 0x41d8 };
#else
enum { kWorldFlagOffset = 0x4488 };
#endif


#if defined(jpn)
#define SetFlagFromObjByte_021e85e8 func_ov025_021e8a88
#endif

extern "C" void* func_ov017_0218b5b0(void);

// USA: func_ov025_021e85e8
#if defined(jpn)
extern "C"
#endif
ARM int SetFlagFromObjByte_021e85e8(unsigned char* obj) {
    unsigned char* base = (unsigned char*)func_ov017_0218b5b0();
    base[kWorldFlagOffset] = 1;
    unsigned char flag = obj[8];
    unsigned char v = 1;
    if (flag == 0) {
        v = 0;
    }
    base[kWorldFlagOffset] = v;
    return 1;
}
