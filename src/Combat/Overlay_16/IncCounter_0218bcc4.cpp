#include <globaldefs.h>

struct CallbackProgressState {
#if defined(jpn)
    unsigned char unknown0[0x3c];
#else
    unsigned char unknown0[0x48];
#endif
    unsigned long long callbackCount;
};
extern struct CallbackProgressState data_ov016_0219d0c0;

// USA: func_ov016_0218bcc4
ARM void IncCounter_0218bcc4(void) {
    data_ov016_0219d0c0.callbackCount++;
}
