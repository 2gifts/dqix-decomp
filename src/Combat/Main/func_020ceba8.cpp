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
void DelayThenSyncBit0_020c9820();
unsigned long IssueRequestAndPumpHandler020ce614(int status);
unsigned long RemapRequestTypeAndRunHandler_020ce5b0(int led, void (*callback)(), int* arg);
unsigned long InvokeReg0x10IfPowcntBit0Set_020ce7e0(int value);

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
                if (IssueRequestAndPumpHandler020ce614(led) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (IssueRequestAndPumpHandler020ce614(led) != PM_SUCCESS);
            }
            else
            {
                if (RemapRequestTypeAndRunHandler_020ce5b0(led, NULL, NULL) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (RemapRequestTypeAndRunHandler_020ce5b0(led, NULL, NULL) != PM_SUCCESS);
            }
        }
        POWCNT |= 1;
        if (InvokeReg0x10IfPowcntBit0Set_020ce7e0(data_021117ec.command16Value) != PM_SUCCESS)
            do
                func_020c976c(RETRY_WAIT_CYCLES);
            while (InvokeReg0x10IfPowcntBit0Set_020ce7e0(data_021117ec.command16Value) != PM_SUCCESS);
        break;
    case PM_LCD_POWER_OFF:
        if (InvokeReg0x10IfPowcntBit0Set_020ce7e0(0) != PM_SUCCESS)
            do
                func_020c976c(RETRY_WAIT_CYCLES);
            while (InvokeReg0x10IfPowcntBit0Set_020ce7e0(0) != PM_SUCCESS);
        if (VBLANK_COUNT - data_021117ec.initCount <= LCD_INIT_WAIT_FRAMES)
        {
            DelayThenSyncBit0_020c9820();
            DelayThenSyncBit0_020c9820();
        }
        POWCNT &= ~1;
        data_021117ec.lcdCount = VBLANK_COUNT;
        if (led != PM_LED_NONE)
        {
            if (isSync)
            {
                if (IssueRequestAndPumpHandler020ce614(led) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (IssueRequestAndPumpHandler020ce614(led) != PM_SUCCESS);
            }
            else
            {
                if (RemapRequestTypeAndRunHandler_020ce5b0(led, NULL, NULL) != PM_SUCCESS)
                    do
                        func_020c976c(RETRY_WAIT_CYCLES);
                    while (RemapRequestTypeAndRunHandler_020ce5b0(led, NULL, NULL) != PM_SUCCESS);
            }
        }
        break;
    }
    return true;
}
