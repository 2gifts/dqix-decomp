#include <globaldefs.h>
#include <System/Interrupts.h>

struct SoundCommand020d24c4 {
    SoundCommand020d24c4* next;
};

struct SoundCommandState020d24c4 {
    SoundCommand020d24c4* freeList;
    unsigned long finishedTag;
    SoundCommand020d24c4* reserveList;
    SoundCommand020d24c4* reserveListEnd;
    SoundCommand020d24c4* freeListEnd;
    int waitingQueueRead;
    int waitingQueueWrite;
    int waitingCount;
    unsigned long currentTag;
};

extern SoundCommandState020d24c4 data_02112780;
extern SoundCommand020d24c4* data_021127a4[9];
extern unsigned char data_02112a60[0x1800];

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
int SendCommandToArm7(int command, int data, bool error);
void WaitUntilChannel7Ready();
extern "C" void* func_020d22f4(unsigned long flags);

// USA: func_020d24c4
extern "C" ARM int func_020d24c4(unsigned long flags) {
    int lastState = DisableIRQInterrupts();
    if (data_02112780.reserveList == NULL) {
        SetIRQInterruptState(lastState);
        return true;
    }
    if (data_02112780.waitingCount >= 8) {
        if (!(flags & 1)) {
            SetIRQInterruptState(lastState);
            return false;
        }
        do {
            func_020d22f4(1);
        } while (data_02112780.waitingCount >= 8);
        if (data_02112780.reserveList == NULL) {
            SetIRQInterruptState(lastState);
            return true;
        }
    }
    CleanInvalidateCacheRange(data_02112a60, sizeof(data_02112a60));
    if (SendCommandToArm7(7, (int)data_02112780.reserveList, false) < 0) {
        if (!(flags & 1)) {
            SetIRQInterruptState(lastState);
            return false;
        }
        while (data_02112780.waitingCount >= 8 ||
               SendCommandToArm7(7, (int)data_02112780.reserveList, false) < 0) {
            SetIRQInterruptState(lastState);
            func_020d22f4(0);
            lastState = DisableIRQInterrupts();
            CleanInvalidateCacheRange(data_02112a60, sizeof(data_02112a60));
            if (data_02112780.reserveList == NULL) {
                SetIRQInterruptState(lastState);
                return true;
            }
        }
    }
    data_021127a4[data_02112780.waitingQueueWrite] = data_02112780.reserveList;
    data_02112780.waitingQueueWrite++;
    if (data_02112780.waitingQueueWrite > 8)
        data_02112780.waitingQueueWrite = 0;
    data_02112780.reserveList = NULL;
    data_02112780.reserveListEnd = NULL;
    data_02112780.waitingCount++;
    data_02112780.currentTag++;
    SetIRQInterruptState(lastState);
    if (flags & 2)
        WaitUntilChannel7Ready();
    return true;
}
