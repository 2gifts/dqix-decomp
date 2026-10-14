#include <globaldefs.h>

// USA: func_020d468c
ARM void ClearBit0At027FFF96_020d468c(void) {
    unsigned short* p = (unsigned short*)0x027fff96;
    if (*p & 1) {
        *p = *p & ~1;
    }
}
