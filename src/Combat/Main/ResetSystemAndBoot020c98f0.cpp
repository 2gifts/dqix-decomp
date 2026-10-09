#include <globaldefs.h>

extern "C" void func_020c9be0();
extern "C" void func_01ff81e4();
unsigned int GenerateLockOwnerID();
void NitroVM_Command_AcquireCardReadResources(unsigned short owner);
unsigned int SetSpecificInterruptsEnabled(unsigned int which);
unsigned int AcknowledgeSpecificInterrupts(unsigned int flagMask);
void ResetDMAChannel(int channel);
void RetrySendIpcCommand(int command);

static inline int IsMultiBootChild()
{
    return *(unsigned short*)0x027ffc40 == 2;
}

// USA: func_020c98f0 // KEEP-NAME
ARM void ResetSystemAndBoot020c98f0(int parameter)
{
    if (IsMultiBootChild())
    {
        func_020c9be0();
    }

    NitroVM_Command_AcquireCardReadResources((unsigned short)GenerateLockOwnerID());

    SetSpecificInterruptsEnabled(1 << 18);
    AcknowledgeSpecificInterrupts(~(1 << 18));
    ResetDMAChannel(0);
    ResetDMAChannel(1);
    ResetDMAChannel(2);
    ResetDMAChannel(3);

    *(volatile unsigned long*)0x027ffc20 = parameter;
    RetrySendIpcCommand(0x10);

    asm
    {
        ldr r0, =0x027e3f80
        ldr r1, =0x400
        sub r0, r0, r1
        mov sp, r0
        bl func_01ff81e4
    }
}
