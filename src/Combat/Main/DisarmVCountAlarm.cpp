#include <globaldefs.h>

ARM unsigned int DisableIRQInterrupts();
ARM unsigned int SetIRQInterruptState(int mask);
struct VCountAlarmNode;
ARM void UnlinkVCountAlarmNode_020c9384(struct VCountAlarmNode* node);

struct AlarmCtx020c949c {
    unsigned int linked;
    char _pad[0x20];
    unsigned int flag24;
};

// USA: func_020c949c
ARM void DisarmVCountAlarm(struct AlarmCtx020c949c* node) {
    unsigned int oldIntr = DisableIRQInterrupts();
    node->flag24 = 1;
    if (node->linked == 0) {
        SetIRQInterruptState(oldIntr);
        return;
    }
    UnlinkVCountAlarmNode_020c9384((struct VCountAlarmNode*)node);
    node->linked = 0;
    SetIRQInterruptState(oldIntr);
}
