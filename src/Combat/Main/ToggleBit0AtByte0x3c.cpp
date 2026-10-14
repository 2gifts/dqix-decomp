#include <globaldefs.h>

struct ToggleBits3c_891b0 {
    unsigned char pad[0x3c];
    unsigned char bit0 : 1;
};

// USA: func_020891b0
ARM void ToggleBit0AtByte0x3c_020891b0(struct ToggleBits3c_891b0* obj) {
    if (obj->bit0) {
        obj->bit0 = 0;
    } else {
        obj->bit0 = 1;
    }
}
