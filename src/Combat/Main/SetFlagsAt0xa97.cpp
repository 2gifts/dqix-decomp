#include <globaldefs.h>

struct FlagBlob02027bac {
#if defined(jpn)
    unsigned char pad[0x9cb];
#else
    unsigned char pad[0xa97];
#endif
    unsigned char flags;
};

// USA: func_02027bac
// JPN: func_02027418
ARM void SetFlagsAt0xa97(struct FlagBlob02027bac* p, unsigned char flags) {
    p->flags |= flags;
}
