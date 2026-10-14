#include <globaldefs.h>

int EnqueueEvent0x1B_020d1fd0(int a, int b);

struct FlagState0210f3c0 { unsigned int f0; unsigned int f4; unsigned int f8; };
extern FlagState0210f3c0 data_0210f3c0;

// USA: func_020bbe64
ARM void ReleaseFlagBits020bbe64(int mask) {
    if (mask == 0) return;
    EnqueueEvent0x1B_020d1fd0(mask, 0);
    data_0210f3c0.f8 &= ~mask;
}
