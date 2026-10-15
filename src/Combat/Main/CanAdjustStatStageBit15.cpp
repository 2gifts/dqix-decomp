#include <globaldefs.h>

struct StatStageStruct02087c30 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int stage0 : 3;
    int stage3 : 3;
    int stage6 : 3;
    int stage9 : 3;
    int stage12 : 3;
    int stage15 : 3;
};

// USA: func_02087c30
ARM int CanAdjustStatStageBit15(StatStageStruct02087c30* p, unsigned char decrease) {
    if (p->flags & 1) return 0;
    if (decrease == 0) {
        if (p->stage15 < 2) return 1;
    } else {
        if (p->stage15 > -2) return 1;
    }
    return 0;
}
