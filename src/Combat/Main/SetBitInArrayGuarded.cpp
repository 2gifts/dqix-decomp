#include <globaldefs.h>

// USA: func_0209609c
ARM void SetBitInArrayGuarded_0209609c(int unused, unsigned char* arr, int index) {
    if (index > 0xcc) return;
    if (index < 0) return;
    arr[index >> 3] |= (unsigned char)(1 << (index & 7));
}
