#include <globaldefs.h>

int CheckByteSetAndByteClear_02012aac(unsigned char* obj);

// USA: func_02012ad0
ARM int TickByteFlagCounter02012ad0(unsigned char* obj) {
    int cond = (obj[0x5f] != 0) && (*(unsigned short*)(obj + 0x24) != 0);
    if (cond) {
        if (*(int*)(obj + 0x58) == 0) {
            if (CheckByteSetAndByteClear_02012aac(obj)) {
                *(int*)(obj + 0x58) = 0xc;
                return 1;
            }
            *(int*)(obj + 0x58) = 2;
            return 1;
        } else {
            *(int*)(obj + 0x58) -= 1;
        }
    } else if (!(obj[0x5f] != 0 && *(unsigned short*)(obj + 0x24) != 0)) {
        *(int*)(obj + 0x58) = 0;
    }
    return 0;
}
