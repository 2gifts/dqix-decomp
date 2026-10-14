#include <globaldefs.h>

struct StateBits5ccc_11544 {
#if defined(jpn)
    char unk[0x5A6C];
#else
    char unk[0x5CCC];
#endif
    signed int flag : 1;
};

// USA: func_02011544
ARM void SetFlag0x5cccBit0_02011544(struct StateBits5ccc_11544* state) {
    state->flag = 1;
}
