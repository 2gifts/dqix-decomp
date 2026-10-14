#include <globaldefs.h>

// USA: func_020d3018
ARM int CompareStrings_020d3018(const char* a, const char* b) {
    while (*a == *b && *a != 0) {
        a++;
        b++;
    }
    return *a - *b;
}
