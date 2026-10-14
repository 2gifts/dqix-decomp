#include <globaldefs.h>

struct ByteSearchStruct {
    char pad[0x1048];
    signed char arr[16];
};

// USA: func_0202bcf8
ARM signed char FindSignedByteSlot_0202bcf8(struct ByteSearchStruct* obj, int value) {
    int i;
    for (i = 0; i < 16; i++) {
        if (obj->arr[i] == value) {
            break;
        }
    }
    if (i == 16) {
        return -1;
    }
    return i;
}
