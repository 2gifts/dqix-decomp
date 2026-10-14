#include <globaldefs.h>

extern "C" void func_020d1f0c(unsigned long chBitMask, unsigned long capBitMask, int alarmBitMask, int flags);
unsigned long GetInterruptSafeQueueField_020d26ec();
extern "C" void func_020d24c4(int block);
void ProcessQueueUntilValueCommitted020d2680(unsigned int commandTag);
extern "C" int func_020c7ea0(void* queue, void** msg, int flags);
void ClearGlobalFlags020bbe94(int mask);
void ReleaseFlagBits020bbe64(int mask);
void ClearFlagBit020bbef8(int alarmNo);
void EnqueueEvent0x19_020d2104(int left, int right, int channel1, int channel3);

struct CaptureParameters020bcf3c {
    int activeFlag;
    int type;
    int format;
    void* bufferL;
    void* bufferR;
    unsigned long bufLen;
    unsigned long blockSize;
    int curBuffer;
    unsigned long chBitMask;
    unsigned long playChBitMask;
    unsigned long capBitMask;
    int alarmNo;
};

struct Statics0210fd74 {
    char pad[0x48];
    int activeFlag;
};

extern Statics0210fd74 data_0210fd74;
extern CaptureParameters020bcf3c data_0210fdbc;
extern char data_0210fd7c;

// USA: func_020bcf3c
extern "C" ARM void func_020bcf3c(void) {
    CaptureParameters020bcf3c* cap = &data_0210fdbc;
    unsigned long commandTag;
    int useAlarm;

    if (!data_0210fd74.activeFlag)
        return;

    useAlarm = cap->alarmNo >= 0 ? 1 : 0;

    func_020d1f0c(cap->playChBitMask, cap->capBitMask, useAlarm ? 1 << cap->alarmNo : 0, 0);

    if (useAlarm) {
        commandTag = GetInterruptSafeQueueField_020d26ec();
        func_020d24c4(1);
        ProcessQueueUntilValueCommitted020d2680(commandTag);

        while (func_020c7ea0(&data_0210fd7c, NULL, 0)) {
        }
    }

    if (cap->capBitMask)
        ClearGlobalFlags020bbe94(cap->capBitMask);
    if (cap->chBitMask)
        ReleaseFlagBits020bbe64(cap->chBitMask);
    if (useAlarm)
        ClearFlagBit020bbef8(cap->alarmNo);

    if (cap->type == 1)
        EnqueueEvent0x19_020d2104(0, 0, 0, 0);

    cap->activeFlag = 0;
}
