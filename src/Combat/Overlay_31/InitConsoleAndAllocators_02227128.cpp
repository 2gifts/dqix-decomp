#include <globaldefs.h>

void SaveAndClearDisplayMode_020c3898(void);
int Is64BitTimerInitialized();
int IsAlarmListInitialized();
int SetVBlankIrqEnable_020c3864(int enable);
void BlankFunction020c36ec(void);
void InitializeROMFilesystem(int dmaChannel);
extern "C" void func_020c9be0(void);
extern "C" void func_020cd890(void);
ARM void InitSlotSystem020cf020(void);

extern "C" void func_ov031_0223dda8(void);
extern int data_ov031_02250c0c;
ARM void InitMainAllocator_0223ce9c(void* a);
extern "C" ARM void func_ov031_0223d780(void);
extern "C" void func_ov031_0223e00c(void);
extern "C" ARM void func_ov031_0223b324(void);
extern "C" void func_ov031_0223cff0(void);
extern "C" void func_ov031_0223bff8(void);
extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" int func_ov031_0221b9b0(void*);
extern "C" unsigned int func_ov031_0223cf70(void**);

// USA: func_ov031_02227128  (semantic: InitConsoleAndAllocators_02227128)  (semantic: InitConsoleAndAllocators_02227128)
extern "C" ARM void func_ov031_02227128(void) {
    volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
    unsigned short oldIme = *ime;
    (void)oldIme;
    *ime = 0;
    SaveAndClearDisplayMode_020c3898();
    *(volatile unsigned int*)0x4001000 &= ~0x10000;
    if (!Is64BitTimerInitialized()) {
        func_020c9be0();
    }
    if (!IsAlarmListInitialized()) {
        func_020c9be0();
    }
    SetVBlankIrqEnable_020c3864(0);
    BlankFunction020c36ec();
    InitializeROMFilesystem(-1);
    func_020cd890();
    InitSlotSystem020cf020();
    SaveAndClearDisplayMode_020c3898();
    *(volatile unsigned int*)0x4001000 &= ~0x10000;
    func_ov031_0223dda8();
    InitMainAllocator_0223ce9c(*(void**)((char*)&data_ov031_02250c0c + 0x4));
    func_ov031_0223d780();
    func_ov031_0223e00c();
    func_ov031_0223b324();
    func_ov031_0223cff0();
    func_ov031_0223bff8();
    void* p = func_ov031_0223cf4c(0x700, 0x20);
    func_ov031_0221b9b0(p);
    func_ov031_0223cf70(&p);
}
