#include <globaldefs.h>

extern "C" void func_020d1f0c(unsigned long chBitMask, unsigned long capBitMask, int alarmBitMask, int flags);
unsigned long GetInterruptSafeQueueField();
extern "C" void func_020d24c4(int block);
extern "C" void _Z39ProcessQueueUntilValueCommitted020d2680j(unsigned int commandTag);
extern "C" int func_020c7ea0(void* queue, void** msg, int flags);
extern "C" void _Z24ClearGlobalFlags020bbe94i(int mask);
extern "C" void _Z23ReleaseFlagBits020bbe64i(int mask);
extern "C" void _Z20ClearFlagBit020bbef8i(int alarmNo);
void EnqueueEvent0x19(int left, int right, int channel1, int channel3);

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
        commandTag = GetInterruptSafeQueueField();
        func_020d24c4(1);
        _Z39ProcessQueueUntilValueCommitted020d2680j(commandTag);

        while (func_020c7ea0(&data_0210fd7c, NULL, 0)) {
        }
    }

    if (cap->capBitMask)
        _Z24ClearGlobalFlags020bbe94i(cap->capBitMask);
    if (cap->chBitMask)
        _Z23ReleaseFlagBits020bbe64i(cap->chBitMask);
    if (useAlarm)
        _Z20ClearFlagBit020bbef8i(cap->alarmNo);

    if (cap->type == 1)
        EnqueueEvent0x19(0, 0, 0, 0);

    cap->activeFlag = 0;
}
