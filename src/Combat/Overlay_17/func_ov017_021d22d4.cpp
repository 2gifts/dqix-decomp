#include <globaldefs.h>
#include "std_library_functions.h"

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Bits021d22d4 {
    unsigned short lo2 : 2;
    unsigned short hi14 : 14;
};

// USA: func_ov017_021d22d4
extern "C" ARM void func_ov017_021d22d4(unsigned short a0, unsigned short a1, void* a2) {
    void* p = GetData02100044();
    unsigned char buf[0x14];
    Bits021d22d4* bits = (Bits021d22d4*)(buf + 4);
    buf[0] = 0x9d;
    bits->lo2 = a0;
    bits->hi14 = a1;

    int len = 0xe;
    if ((unsigned int)(a1 + 0xe) > 0x2e0) {
        len = 0x2e0 - a1;
    }
    if (len >= 0) {
        memcpy((unsigned char*)bits + 2, (unsigned char*)a2 + a1, len);
        func_0205e330(p, buf, 0);
    }
}
