#include <globaldefs.h>
#include "std_library_functions.h"
int StringLength_020d2ff0(const char* s);
// USA: func_02068e1c
char* JoinDelimitedParts02068e1c(char* dst, char* first, char* second, char* third) {
    char* cursor = dst;
    char* a = strstr(dst, first);
    if (!a) {
        goto done;
    }
    {
        char* b = strstr(a, second);
        if (!b) {
            goto done;
        }
        char* c = strstr(b, third);
        if (!c) {
            goto done;
        }
        cursor = a + StringLength_020d2ff0(first);
        int thirdLen = StringLength_020d2ff0(third);
        char* out = cursor;
        char* src = cursor;
        for (;;) {
            if (src == b) {
                src = c + thirdLen;
            }
            char ch = *src;
            *out = ch;
            if (ch == 0) {
                break;
            }
            out++;
            src++;
        }
    }
done:
    return cursor;
}
