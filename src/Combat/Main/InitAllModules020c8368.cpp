#include <globaldefs.h>

extern "C" void func_020c83b0(void);
void InitializeInterProcessorCommunication(void);
void InitializeGamecardBusOwnership(void);
extern "C" void func_020c84b4(void);
void InitializeInterruptContextBlock_020c6ad4(void);
#if defined(jpn)
#define func_020c745c func_020c8f28
#endif
void StoreSharedMemMagicWords(void);
extern "C" void func_020c8a3c(void);
void SetWramCntThenReset(void);
void InitModule020c9288(void);
void ResetTable020c9a54(void);
extern "C" void func_020c745c(void);
extern "C" void func_020c983c(void);
extern "C" void func_020d15fc(void);
void InitializeCardReading(void);
extern "C" void func_020ce270(void);
void WaitForVCountZero(void);

// USA: func_020c8368
ARM void InitAllModules020c8368(void) {
    func_020c83b0();
    InitializeInterProcessorCommunication();
    InitializeGamecardBusOwnership();
    func_020c84b4();
    InitializeInterruptContextBlock_020c6ad4();
    StoreSharedMemMagicWords();
    func_020c8a3c();
    SetWramCntThenReset();
    InitModule020c9288();
    ResetTable020c9a54();
    func_020c745c();
    func_020c983c();
    func_020d15fc();
    InitializeCardReading();
    func_020ce270();
    WaitForVCountZero();
}
