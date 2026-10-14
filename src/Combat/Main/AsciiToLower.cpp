#include <globaldefs.h>

// USA: func_020d8550
ARM signed char AsciiToLower_020d8550(int c) {
    int cond = (c & 0xff) >= 'A' && (c & 0xff) <= 'Z';
    if (cond) {
        c += 0x20;
    }
    return c;
}
