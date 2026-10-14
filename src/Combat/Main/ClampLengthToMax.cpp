#include <globaldefs.h>

// USA: func_02084e4c
ARM unsigned int ClampLengthToMax_02084e4c(unsigned int a, unsigned int start, unsigned int length, unsigned int max) {
    unsigned int end = start + length;
    if (start == max) {
        length = 0;
    } else if (start > max) {
        length = 0;
    } else if (end > max) {
        length = max - start;
    }
    return length;
}
