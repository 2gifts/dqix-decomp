#include <globaldefs.h>

struct StateBits5ccc_1155c {
#if defined(jpn)
    char unk[0x5A6C];
#else
    char unk[0x5CCC];
#endif
    signed int flag : 1;
};

// USA: func_0201155c
ARM void ClearFlag0x5cccBit0_0201155c(struct StateBits5ccc_1155c* state) {
    state->flag = 0;
}
