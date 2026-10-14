#include <globaldefs.h>

// USA: func_02012444
ARM int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask) {
    if ((obj[0] & mask) != 0 && (obj[1] & mask) == 0) {
        return 1;
    }
    return 0;
}
