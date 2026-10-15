#include <globaldefs.h>

struct StatStageStruct02087e18 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 21;
    int stage : 3;
};

// USA: func_02087e18
ARM int CanAdjustStatStageBit21(StatStageStruct02087e18* p, unsigned char decrease) {
    if (p->flags & 1) return 0;
    if (decrease == 0) {
        if (p->stage < 2) return 1;
    } else {
        if (p->stage > -2) return 1;
    }
    return 0;
}
