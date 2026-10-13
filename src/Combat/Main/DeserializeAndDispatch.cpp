#include <globaldefs.h>
#include "std_library_functions.h"

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

struct Rec0204a848 {
    unsigned int   f0;
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    unsigned char  fa;
    unsigned char  fb;
};

// USA: func_0204a848
ARM int DeserializeAndDispatch(Rec0204a848* dst, void (*fp)(const void*, int, unsigned int), unsigned char* src, void*) {
    int val;
    int tmp;
    memcpy(&tmp, src, 4);
    memcpy(&dst->f4, src + 4, 2);
    memcpy(&dst->f6, src + 6, 2);
    memcpy(&dst->f8, src + 8, 2);
    memcpy(&dst->fa, src + 0xa, 1);
    memcpy(&dst->fb, src + 0xb, 1);
    memcpy(&val, src + 0xc, 4);
    CleanInvalidateCacheRange(src + 0x10, val);
    fp(src + 0x10, dst->f0, val);
    return 0;
}
