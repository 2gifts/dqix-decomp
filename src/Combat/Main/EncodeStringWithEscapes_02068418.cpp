#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry02068418 {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

struct Entry02068418* FindEntryByKey0204254c(int key, int tableIdx);
char* FindUnescapedAngleBracket_020424ac(char* str);
void ToUpperBounded_02067f5c(signed char* s, int count);
extern char data_020f08f4[];

// USA: func_02068418  (semantic: EncodeStringWithEscapes_02068418)
extern "C" ARM void func_02068418(void* unused, char* src, char* dst, int id) {
    if (src == 0 || dst == 0) return;
    signed char c;
    for (;;) {
        c = *src;
        if (c == 0) {
            break;
        }
        if (c == 0x5c && src[1] == 0x6e) {
            dst[0] = c;
            dst[1] = src[1];
            src += 2;
            dst += 2;
            continue;
        }
        struct Entry02068418* e = FindEntryByKey0204254c((int)src, id);
        if (e != 0) {
            int step = e->field5;
            memcpy(dst, src, step);
            src += step;
            dst += step;
            continue;
        }
        if (c == 0x3c) {
            char* gt = FindUnescapedAngleBracket_020424ac(src);
            if (gt != 0) {
                int len = gt - src;
                memcpy(dst, src, len + 1);
                ToUpperBounded_02067f5c((signed char*)dst, len + 1);
                src += len + 1;
                dst += len + 1;
                continue;
            }
        }
        if (c == 0x20 || c == 0x2f || c == 0xa) {
            *dst++ = *src++;
            continue;
        }
        memcpy(dst, data_020f08f4, 3);
        src++;
        dst += 3;
    }
    *dst = c;
}
