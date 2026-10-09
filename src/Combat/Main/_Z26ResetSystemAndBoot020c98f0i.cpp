#include <globaldefs.h>

extern "C" void func_020c9be0(void);
extern "C" void func_01ff81e4(void);
int GenerateLockOwnerID(void);
void NitroVM_Command_AcquireCardReadResources(unsigned short);
unsigned int SetSpecificInterruptsEnabled(unsigned int);
unsigned int AcknowledgeSpecificInterrupts(unsigned int);
void ResetDMAChannel(int);
void RetrySendIpcCommand(int);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c98f0
extern "C" ARM void _Z26ResetSystemAndBoot020c98f0i(int arg)
{
    int ok = (*(volatile unsigned short *)0x027FFC40 == 2);
    if (ok != 0) {
        func_020c9be0();
    }
    NitroVM_Command_AcquireCardReadResources((unsigned short)GenerateLockOwnerID());
    SetSpecificInterruptsEnabled(0x40000);
    AcknowledgeSpecificInterrupts(0xfffbffff);
    ResetDMAChannel(0);
    ResetDMAChannel(1);
    ResetDMAChannel(2);
    ResetDMAChannel(3);
    *(volatile int *)0x027FFC20 = arg;
    RetrySendIpcCommand(0x10);
    unsigned int base = 0x027E3F80;
    unsigned int off = 0x400;
    __asm("mov sp, %0" : : "r"(base - off));
    func_01ff81e4();
}