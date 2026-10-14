#include <globaldefs.h>

struct SearchStruct;
struct ByteSearchStruct;
signed char FindSignedByteIndex_0202bcbc(struct SearchStruct* obj, int value);
signed char FindSignedByteSlot_0202bcf8(struct ByteSearchStruct* obj, int value);

// USA: func_0202c5bc
ARM void SetFlagBitAt0xe_0202c5bc(struct SearchStruct* obj, int value) {
    int idx = FindSignedByteIndex_0202bcbc(obj, value);
    if (idx < 0) {
        idx = FindSignedByteSlot_0202bcf8((struct ByteSearchStruct*)obj, value);
        if (idx < 0) return;
    }
    *((unsigned char*)obj + 0x100e) |= (1 << idx);
}
