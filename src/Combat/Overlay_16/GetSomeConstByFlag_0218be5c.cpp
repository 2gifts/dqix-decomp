#include <globaldefs.h>

extern char data_ov016_0219d0c0[];

#if defined(jpn)
static const int bankSelectionOffset = 0x34;
#else
static const int bankSelectionOffset = 0x18;
#endif

// Shares its selector with func_ov016_0218be7c, which toggles that state
// after changing display mode. Zero selects 0x06820000; nonzero selects
// 0x06800000.
// USA: func_ov016_0218be5c
// JPN: func_ov016_0218c93c
ARM int GetSomeConstByFlag_0218be5c(void) {
    int bankSelection = *(int*)(data_ov016_0219d0c0 + bankSelectionOffset);
    if (bankSelection == 0) {
        return 0x6820000;
    }
    return 0x6800000;
}
