#include <globaldefs.h>

// USA: func_02012468
ARM int TestFlagInSecondWord_02012468(unsigned short* obj, unsigned int mask) {
    if ((obj[0] & mask) == 0) {
        if (obj[1] & mask) {
            return 1;
        }
    }
    return 0;
}
