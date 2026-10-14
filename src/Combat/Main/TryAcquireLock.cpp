#include <globaldefs.h>

struct LockState020ce128 { unsigned char pad[0x1c]; int lock; };
extern struct LockState020ce128 data_021117ec;

// USA: func_020ce128
ARM int TryAcquireLock_020ce128(void) {
    if (data_021117ec.lock != 0) {
        return 0;
    }
    data_021117ec.lock = 1;
    return 1;
}
