#include <globaldefs.h>

struct StatStageStruct02087f78 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 27;
    int stage : 3;
};

void ClearFlags0x14And0x58_02087ff0(void* obj);

// USA: func_02087f78
ARM int SetStatStageBit27(struct StatStageStruct02087f78* p, int delta) {
    int newStage = p->stage + delta;
    if (newStage > 2) newStage = 2;
    if (newStage < -2) newStage = -2;
    if (newStage == 0) {
        ClearFlags0x14And0x58_02087ff0(p);
        return 0;
    }
    p->stage = newStage;
    *((unsigned char*)p + 0x77) = 5;
    *((unsigned char*)p + 0x9a) = 0;
    p->flags |= 0x2000000;
    return p->stage;
}
