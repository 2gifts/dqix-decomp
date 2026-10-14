#include <globaldefs.h>

struct HwStatus020ce114 { unsigned char pad[0x38]; unsigned short flags; };
extern struct HwStatus020ce114 data_021117b0;

// USA: func_020ce114
ARM int GetMaskedStatus_020ce114(int mask) {
    return data_021117b0.flags & mask;
}
