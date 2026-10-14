#include <globaldefs.h>

// USA: func_0206df6c
ARM void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value) {
    int i = bit / 8;
    unsigned char mask = 1 << (bit % 8);
    unsigned int v = array[i];
    if (value != 0) {
        v |= mask;
    } else {
        v &= ~mask;
    }
    array[i] = v;
}
