#include <globaldefs.h>

struct HwStatus020ce0fc { unsigned char pad[0x3a]; volatile unsigned short flags; };
extern struct HwStatus020ce0fc data_021117b0;

// USA: func_020ce0fc
ARM void WaitWhileFlagsSet_020ce0fc(int mask) {
    while (data_021117b0.flags & mask) {}
}
