#include <globaldefs.h>

struct SearchStruct {
    char pad[0x1038];
    signed char arr[16];
};

// USA: func_0202bcbc
ARM signed char FindSignedByteIndex_0202bcbc(struct SearchStruct* obj, int value) {
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
