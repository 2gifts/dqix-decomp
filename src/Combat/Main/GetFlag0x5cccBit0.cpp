#include <globaldefs.h>

struct StateBits5ccc_11570 {
#if defined(jpn)
    char unk[0x5a6c];
#else
    char unk[0x5CCC];
#endif
    signed int flag : 1;
};

// USA: func_02011570
ARM int GetFlag0x5cccBit0(struct StateBits5ccc_11570* state) {
    return state->flag;
}
