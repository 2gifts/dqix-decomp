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

// Registered as the event-0x12 callback by func_ov016_0218bce8.
// The playback worker subtracts this count from produced blocks when checking
// buffer space; the duration represented by one callback is not established here.
// USA: func_ov016_0218bcc4
// JPN: func_ov016_0218c7a4
ARM void IncCounter_0218bcc4(void) {
    data_ov016_0219d0c0.callbackCount++;
}
