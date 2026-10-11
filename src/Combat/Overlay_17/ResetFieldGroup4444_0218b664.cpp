#include <globaldefs.h>

// USA: func_ov017_0218b664
ARM void ResetFieldGroup4444_0218b664(char *base) {
    base += 0x4000;
#if defined(jpn)
    base -= 0x2b0;
#endif
    base[0x444] = 0;
    base[0x445] = 0;
    base[0x447] = -1;
    base[0x448] = 0;
    base[0x449] = 0;
}
