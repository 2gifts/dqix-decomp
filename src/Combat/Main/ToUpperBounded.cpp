#include <globaldefs.h>

// USA: func_02067f5c
ARM void ToUpperBounded_02067f5c(signed char* s, int count) {
    if (s == NULL) {
        return;
    }
    int i = 0;
    while (i < count) {
        int c = *s;
        if (c == 0) {
            return;
        }
        if (c >= 0x61 && c <= 0x7a) {
            c = c - 0x20;
        }
        *s = (signed char)c;
        s++;
        i++;
    }
}
