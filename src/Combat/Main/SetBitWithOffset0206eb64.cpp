#include <globaldefs.h>

void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);

// USA: func_0206eb64
ARM void SetBitWithOffset0206eb64(unsigned char* obj, int bit, int value) {
    if (bit >= 0x400) {
        SetOrClearBitInArray_0206df6c(obj, obj + 0x8c, bit + 0x6fa, value);
        return;
    }
    SetOrClearBitInArray_0206df6c(obj, obj + 0x8c, bit, value);
}
