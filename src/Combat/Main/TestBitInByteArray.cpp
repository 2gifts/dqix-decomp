#include <globaldefs.h>

// USA: func_0206dfb0
ARM int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index) {
    unsigned char mask;
    if (index < 0) {
        return 0;
    }
    mask = 1 << (index % 8);
    return mask & arr[index / 8];
}
