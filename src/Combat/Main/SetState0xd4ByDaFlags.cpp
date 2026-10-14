#include <globaldefs.h>

// USA: func_0208cf98
ARM void SetState0xd4ByDaFlags_0208cf98(unsigned char* obj) {
    unsigned short da = *(unsigned short*)(obj + 0xda);
    if (da & 1) {
        obj[0xd4] = 2;
        obj[0xd5] = 0;
        return;
    }
    if (da & 2) {
        obj[0xd4] = 3;
        obj[0xd5] = 0;
    }
}
