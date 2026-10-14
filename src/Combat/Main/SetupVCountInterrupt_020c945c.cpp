#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" void func_020c94e4(void);
void SetVCountCompare_020c383c(int lyc);

// USA: func_020c945c  (semantic: SetupVCountInterrupt_020c945c)
extern "C" ARM void func_020c945c(void* obj) {
    SetInterruptHandler(IRQ_MASK_LCD_VCOUNTER_MATCH, (const void*)func_020c94e4);
    SetVCountCompare_020c383c(*(short*)((char*)obj + 0x10));
    *(volatile unsigned short*)0x4000004 |= 0x20;
    EnableSpecificInterrupts(IRQ_MASK_LCD_VCOUNTER_MATCH);
}
