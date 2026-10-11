#include <globaldefs.h>

struct Struct5e00 {
#if defined(jpn)
    char pad[0x5ff0];
#else
    char pad[0x5e00];
#endif
    unsigned char count;
    unsigned char flags;
    char pad2[2];
    int values[1];
};

// USA: func_ov000_021673e0
// JPN: func_ov000_02168b20
ARM int FindAndSetFreeSlot021673e0(struct Struct5e00* s) {
    int i;
    for (i = 0; i < s->count; i++) {
        if (!(s->flags & (1 << i))) {
            s->flags |= (1 << i);
            return s->values[i];
        }
    }
    return 0;
}
