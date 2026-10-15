#include <globaldefs.h>

struct StatStageStruct02087860 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int stage0 : 3;
    int stage3 : 3;
};

// USA: func_02087860
ARM int CanAdjustStatStageBit3(StatStageStruct02087860* p, unsigned char decrease) {
    if (p->flags & 1) return 0;
    if (decrease == 0) {
        if (p->stage3 < 2) return 1;
    } else {
        if (p->stage3 > -2) return 1;
    }
    return 0;
}
