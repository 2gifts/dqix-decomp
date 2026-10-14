#include <globaldefs.h>
#include "std_library_functions.h"

void* GetData02100044_0202ae24(void);
extern "C" void* func_0205ec34(void* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Bits021cdc24 {
    unsigned short lo2 : 2;
    unsigned short hi14 : 14;
};

// USA: func_ov017_021cdc24  (semantic: EnqueueEventTag146_021cdc24)
extern "C" ARM void func_ov017_021cdc24(int a0, int a1) {
    void* p = GetData02100044_0202ae24();
    unsigned char buf[0x14];
    Bits021cdc24* bits = (Bits021cdc24*)(buf + 4);
    bits->lo2 = a0;
    buf[0] = 0x92;
    bits->hi14 = a1;

    unsigned char* result = (unsigned char*)func_0205ec34(p);
    int len = 0xe;
    if ((unsigned int)(a1 + 0xe) > 0xfd) {
        len = 0xfd - a1;
    }
    if (len >= 0) {
        memcpy((unsigned char*)bits + 2, result + a1, len);
        func_0205e330(p, buf, 0);
    }
}
