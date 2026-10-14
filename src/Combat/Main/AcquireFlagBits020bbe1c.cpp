#include <globaldefs.h>

int EnqueueEvent0x1A_020d1fb0(int a, int b);

struct FlagState0210f3c0 { unsigned int f0; unsigned int f4; unsigned int f8; };
extern FlagState0210f3c0 data_0210f3c0;

// USA: func_020bbe1c
ARM int AcquireFlagBits020bbe1c(int mask) {
    if (mask == 0) return 1;
    if (mask & data_0210f3c0.f8) return 0;
    EnqueueEvent0x1A_020d1fb0(mask, 0);
    data_0210f3c0.f8 |= mask;
    return 1;
}
