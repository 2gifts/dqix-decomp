#include <globaldefs.h>

struct StatStageStruct02087c84 {
    char pad14[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 15;
    int stage : 3;
};

void ClearBattleFlags0x14And0x58_02087cfc(void* obj);

// USA: func_02087c84
ARM int SetStatStageBit15(struct StatStageStruct02087c84* p, int delta) {
    int newStage = p->stage + delta;
    if (newStage > 2) newStage = 2;
    if (newStage < -2) newStage = -2;
    if (newStage == 0) {
        ClearBattleFlags0x14And0x58_02087cfc(p);
        return 0;
    }
    p->stage = newStage;
    *((unsigned char*)p + 0x73) = 5;
    *((unsigned char*)p + 0x96) = 0;
    p->flags |= 0x8000;
    return p->stage;
}
