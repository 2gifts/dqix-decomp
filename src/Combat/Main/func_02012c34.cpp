#include <globaldefs.h>

struct AllocatorUnion;
struct S02012244;

extern "C" {
    void _Z22InitAllModules020c8368v(void);
    void _Z21BlankFunction020c36ecv(void);
    void _Z31InitDisplayAndClearVram020c36f0v(void);
    void func_020ce270(void);
    void _Z22InitSlotSystem020cf020v(void);
    void _Z20Initialize64BitTimerv(void);
    void _Z25InitializeActiveAlarmListv(void);
    void _Z18InitModule020c9288v(void);
    void _Z23InitializeResourceMutexv(void);
    unsigned int _Z28SetSpecificInterruptsEnabledj(unsigned int which);
    void _Z19SetInterruptHandlerjPKv(unsigned int mask, const void* handler);
    void _Z24EnableSpecificInterruptsj(unsigned int mask);
    int _Z18SetVBlankIrqEnablei(int enable);
    void _Z25InitMainAllocator02012d18P14AllocatorUnion(AllocatorUnion* alloc);
    void _Z23InitializeROMFilesystemi(int dmaChannel);
    void _Z23ChangeROMLoadDMAChannelj(int channel);
    void _Z31InitBattleModeAndCommit020758a8v(void);
    void func_020bbd14(void);
    void _Z18InitFields02012244P9S02012244(S02012244* s);
    void _Z26InitBattlerContext0201282cPh(unsigned char* obj);
    void _Z25ResetElapsedState020e1114v(void);
    void _Z44InitOverlay17ObjAndBumpBattleCounter02012bd8v(void);
}

extern int data_020f2270;
extern unsigned char data_02114e00;
extern AllocatorUnion data_02114e20;
extern S02012244 data_02114e30;
extern int data_02114e50;
extern unsigned char data_02114e54[];

// USA: func_02012c34
extern "C" ARM void func_02012c34(void) {
    _Z22InitAllModules020c8368v();
    _Z21BlankFunction020c36ecv();
    data_020f2270 = 0;
    _Z31InitDisplayAndClearVram020c36f0v();
    func_020ce270();
    _Z22InitSlotSystem020cf020v();
    _Z20Initialize64BitTimerv();
    _Z25InitializeActiveAlarmListv();
    _Z18InitModule020c9288v();
    _Z23InitializeResourceMutexv();
    _Z28SetSpecificInterruptsEnabledj(0);
    _Z19SetInterruptHandlerjPKv(1, (const void*)_Z44InitOverlay17ObjAndBumpBattleCounter02012bd8v);
    _Z24EnableSpecificInterruptsj(1);
    _Z24EnableSpecificInterruptsj(0xf08);
    volatile unsigned short* ime = (volatile unsigned short*)0x04000208;
    *ime;
    *ime = 1;
    _Z18SetVBlankIrqEnablei(1);
    _Z25InitMainAllocator02012d18P14AllocatorUnion(&data_02114e20);
    _Z24EnableSpecificInterruptsj(0x40000);
    _Z23InitializeROMFilesystemi(2);
    _Z23ChangeROMLoadDMAChannelj(2);
    _Z31InitBattleModeAndCommit020758a8v();
    func_020bbd14();
    _Z18InitFields02012244P9S02012244(&data_02114e30);
    _Z26InitBattlerContext0201282cPh(data_02114e54);
    _Z25ResetElapsedState020e1114v();
    data_02114e00 = 0;
    data_02114e50 = 0;
}