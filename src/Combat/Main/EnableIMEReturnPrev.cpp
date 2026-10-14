#include <globaldefs.h>

// USA: func_020d6c9c
ARM unsigned short EnableIMEReturnPrev_020d6c9c(void) {
    volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
    unsigned short old = *ime;
    *ime = 1;
    return old;
}
