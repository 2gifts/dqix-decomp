#include <globaldefs.h>

struct FieldFlagBlock {
#if defined(jpn)
    char unk[0x617C];
#else
    char unk[0x63DC];
#endif
    union {
        unsigned char raw;
        struct {
            unsigned char active : 1;
        } bits;
    } flags;
};

// USA: func_02011b24
ARM void ResetAndEnableFieldFlag(struct FieldFlagBlock* block) {
    block->flags.raw = 0;
    block->flags.bits.active = 1;
}
