#include <globaldefs.h>

struct SearchStruct {
    char pad[0x1038];
    signed char arr[16];
};
struct ByteSearchStruct;

signed char FindSignedByteIndex_0202bcbc(struct SearchStruct* obj, int value);
signed char FindSignedByteSlot_0202bcf8(struct ByteSearchStruct* obj, int value);

// USA: func_0202c600
ARM void ClearSearchFlagBit0202c600(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex_0202bcbc(obj, value);
    if (idx < 0) {
        idx = FindSignedByteSlot_0202bcf8((struct ByteSearchStruct*)obj, value);
        if (idx < 0) return;
    }
    *((unsigned char*)obj + 0x100e) &= ~(1 << idx);
}
