#include <globaldefs.h>

struct SystemWork
{
    char unknown_0[0x3c];
    unsigned long vblankCount;
    char unknown_40[0x80 - 0x40];
    unsigned char userSettings[0x74];
    unsigned char macAddress[6];
    char unknown_fa[0x1e8 - 0xfa];
    unsigned char realTimeClock[8];
    char unknown_1f0[0x390 - 0x1f0];
    unsigned long micLastAddress;
    unsigned short micSamplingData;
    char unknown_396[2];
    unsigned short wirelessSignal;
    char unknown_39a[0x3aa - 0x39a];
    unsigned char touchPanel[4];
};

#define SYSTEM_WORK ((const SystemWork*)0x027ffc00)
#define BUTTONS_XY (*(volatile unsigned short*)0x027fffa8)
#define KEYINPUT (*(volatile unsigned short*)0x04000130)
#define GXSTAT (*(volatile unsigned long*)0x04000600)
#define VCOUNT (*(volatile unsigned short*)0x04000006)

extern volatile unsigned long long data_02111640;

unsigned short GetMain16BitTimerCounter();

static inline long GetVCount()
{
    return VCOUNT;
}

// USA: func_020c9b10
extern "C" ARM void func_020c9b10(unsigned long* buffer)
{
    const SystemWork* work = SYSTEM_WORK;
    const unsigned char* macAddress = work->macAddress;

    buffer[0] = (unsigned long)((GetVCount() << 16) | GetMain16BitTimerCounter());
    buffer[1] = (unsigned long)(*(unsigned short*)(macAddress + 4) << 16) ^ (unsigned long)data_02111640;
    buffer[2] = (unsigned long)(data_02111640 >> 32) ^ *(unsigned long*)macAddress ^ work->vblankCount;
    buffer[2] ^= GXSTAT;
    buffer[3] = *(unsigned long*)&work->realTimeClock[0];
    buffer[4] = *(unsigned long*)&work->realTimeClock[4];
    buffer[5] = ((unsigned long)work->micSamplingData << 16) ^ work->micLastAddress;
    buffer[6] = (unsigned long)((*(unsigned short*)&work->touchPanel[0] << 16) | *(unsigned short*)&work->touchPanel[2]);
    buffer[7] = (unsigned long)((work->wirelessSignal << 16) | (KEYINPUT | BUTTONS_XY));
}
