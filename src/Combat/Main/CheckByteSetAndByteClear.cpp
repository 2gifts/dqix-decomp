#include <globaldefs.h>

// USA: func_02012aac
ARM int CheckByteSetAndByteClear_02012aac(unsigned char* obj) {
    if (obj[0x5d] != 0 && obj[0x5e] == 0) {
        return 1;
    }
    return 0;
}
