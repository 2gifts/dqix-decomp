#include <globaldefs.h>

ARM int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);

// USA: func_020a35f8
ARM int CountSetBitsAt0x34_020a35f8(unsigned char* obj) {
    int count = 0;
    int i;
    for (i = 0; i < 4; i++) {
        if (TestBitAt0x34_020a35e0(obj, i)) {
            count++;
        }
    }
    return count;
}
