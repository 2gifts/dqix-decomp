#include <globaldefs.h>

short FindShortIndex0206e3e8(int unused, int key);
void SetOrClearBitInArray_0206df6c(void* unused, unsigned char* array, int bit, int value);

// USA: func_0206e348
ARM void SetKeyedArrayBit0206e348(unsigned char* obj, int index, int value) {
    int idx = FindShortIndex0206e3e8((int)obj, (short)index);
    if (idx - 0x11 < 0) return;
    SetOrClearBitInArray_0206df6c(obj, obj + 0x8c, idx + 0xbf1, value);
}
