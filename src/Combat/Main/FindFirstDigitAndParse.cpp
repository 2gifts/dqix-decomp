#include <globaldefs.h>

extern "C" int func_02005a94(signed char*);

// USA: func_02068200
ARM int FindFirstDigitAndParse_02068200(signed char* s) {
    while (*s != 0) {
        if (*s >= 0x30 && *s <= 0x39)
            return func_02005a94(s);
        s++;
    }
    return 0;
}
