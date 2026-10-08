#include <globaldefs.h>

#define VBLANK_COUNT (*(volatile unsigned long*)0x027ffc3c)
#define POWCNT (*(volatile unsigned short*)0x04000304)

#define PM_SUCCESS 0
#define PM_LCD_POWER_OFF 0
#define PM_LCD_POWER_ON 1
#define PM_LED_NONE 0

#define LCD_OFF_WAIT_FRAMES 7
#define LCD_INIT_WAIT_FRAMES 2
#define RETRY_WAIT_CYCLES 0xa3a47

struct PMStatics
{
    unsigned short isInit;
    unsigned long lcdCount;
    unsigned long initCount;
    volatile int sleepEndFlag;
    unsigned long command16Value;
};

extern PMStatics data_021117ec;

extern "C" void func_020c976c(unsigned long cycles);
void DelayThenSyncBit0();
extern "C" unsigned long _Z34IssueRequestAndPumpHandler020ce614i(int status);
unsigned long RemapRequestTypeAndRunHandler(int led, void (*callback)(), int* arg);
unsigned long InvokeReg0x10IfPowcntBit0Set(int value);

// USA: func_020ceba8
extern "C" ARM int func_020ceba8(int sw, int led, int skip, int isSync)
{
    switch (sw)
    {
    case PM_LCD_POWER_ON:
        if (!skip && VBLANK_COUNT - data_021117ec.lcdCount <= LCD_OFF_WAIT_FRAMES)
            return false;
        if (led != PM_LED_NONE)
        {
            if (isSync)
            {
                if (_Z34IssueRequestAndPumpHandler020ce614i(led) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (_Z34IssueRequestAndPumpHandler020ce614i(led) != PM_SUCCESS);
            }
            else
            {
                if (RemapRequestTypeAndRunHandler(led, NULL, NULL) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (RemapRequestTypeAndRunHandler(led, NULL, NULL) != PM_SUCCESS);
            }
        }
        POWCNT |= 1;
        if (InvokeReg0x10IfPowcntBit0Set(data_021117ec.command16Value) != PM_SUCCESS)
            do
                func_020c976c(RETRY_WAIT_CYCLES);
            while (InvokeReg0x10IfPowcntBit0Set(data_021117ec.command16Value) != PM_SUCCESS);
        break;
    case PM_LCD_POWER_OFF:
        if (InvokeReg0x10IfPowcntBit0Set(0) != PM_SUCCESS)
            do
                func_020c976c(RETRY_WAIT_CYCLES);
            while (InvokeReg0x10IfPowcntBit0Set(0) != PM_SUCCESS);
        if (VBLANK_COUNT - data_021117ec.initCount <= LCD_INIT_WAIT_FRAMES)
        {
            DelayThenSyncBit0();
            DelayThenSyncBit0();
        }
        POWCNT &= ~1;
        data_021117ec.lcdCount = VBLANK_COUNT;
        if (led != PM_LED_NONE)
        {
            if (isSync)
            {
                if (_Z34IssueRequestAndPumpHandler020ce614i(led) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (_Z34IssueRequestAndPumpHandler020ce614i(led) != PM_SUCCESS);
            }
            else
            {
                if (RemapRequestTypeAndRunHandler(led, NULL, NULL) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (RemapRequestTypeAndRunHandler(led, NULL, NULL) != PM_SUCCESS);
            }
        }
        break;
    }
    return true;
}
