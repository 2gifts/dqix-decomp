#include <globaldefs.h>

// USA: func_02042af4
ARM void ClearBitInArray_02042af4(int unused, unsigned char* arr, int index) {
    arr[index >> 3] &= ~(1 << (index & 7));
}
