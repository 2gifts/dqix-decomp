#include <globaldefs.h>

struct StatStageStruct02087d78 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 18;
    int stage : 3;
};

void ClearFlagsAndBytes_02087df0(void* obj);

// USA: func_02087d78
ARM int SetStatStageBit18(struct StatStageStruct02087d78* p, int delta) {
    int newStage = p->stage + delta;
    if (newStage > 2) newStage = 2;
    if (newStage < -2) newStage = -2;
    if (newStage == 0) {
        ClearFlagsAndBytes_02087df0(p);
        return 0;
    }
    p->stage = newStage;
    *((unsigned char*)p + 0x74) = 5;
    *((unsigned char*)p + 0x97) = 0;
    p->flags |= 0x10000;
    return p->stage;
}
