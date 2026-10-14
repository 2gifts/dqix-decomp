#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry020695f4 {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char pad5 : 1;
    signed char flag5 : 1;
    char pad6[2];
};

char* FindUnescapedAngleBracket_020424ac(char* str);
extern "C" int func_02001aec(void* a, void* b, int n);
struct Entry020695f4* FindEntryByKey0204254c(int key, int tableIdx);
void ToUpperBounded_02067f5c(signed char* s, int count);

extern char data_020f0916[];

// USA: func_020695f4
extern "C" ARM void func_020695f4(void* unused, char* src, char* dst, int id) {
    for (;;) {
        char c = *src;
        if (c == 0) {
            break;
        }
        if (c == '<') {
            char* gt = FindUnescapedAngleBracket_020424ac(src);
            if (gt != 0 && func_02001aec(src + 1, data_020f0916, 4) == 0) {
                src = gt + 1;
                struct Entry020695f4* e = FindEntryByKey0204254c((int)src, id);
                if (e != 0 && e->flag5) {
                    int len = e->field5;
                    memcpy(dst, src, len);
                    ToUpperBounded_02067f5c((signed char*)dst, len);
                    src += len;
                    dst += len;
                }
                continue;
            }
        }
        *dst++ = *src++;
    }
    *dst = 0;
}
