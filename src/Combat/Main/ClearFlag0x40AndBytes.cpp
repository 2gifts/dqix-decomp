#include <globaldefs.h>

// USA: func_020890a4
ARM void ClearFlag0x40AndBytes_020890a4(unsigned char* obj) {
    ((int*)obj)[6] &= ~0x40;
    obj[0x7a] = 0;
    obj[0x9d] = 0;
}
