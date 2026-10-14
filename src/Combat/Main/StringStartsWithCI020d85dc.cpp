#include <globaldefs.h>

signed char AsciiToLower_020d8550(int c);

// USA: func_020d85dc
ARM int StringStartsWithCI020d85dc(const char* str, const char* prefix) {
    if (str == 0) {
        return 0;
    }
    if (prefix == 0) {
        return 0;
    }
    if (str == prefix) {
        return 1;
    }
    signed char a, b;
    while ((a = *str) != 0 && (b = *prefix) != 0 && AsciiToLower_020d8550(a) == AsciiToLower_020d8550(b)) {
        str++;
        prefix++;
    }
    return (*prefix == 0) ? 1 : 0;
}
