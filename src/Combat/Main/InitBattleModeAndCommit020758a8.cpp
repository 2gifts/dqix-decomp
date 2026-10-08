#include <globaldefs.h>

void InitializeCardReading(void);
void SetReadContextPriority(unsigned int priority);
int GenerateLockOwnerID(void);
extern "C" void func_020c9be0(void);
void SelectBattleContextMode2(int mode);
int DispatchCartridgeReadToArm7(void* handle);
extern "C" void _Z24PrepareAndCommit020d0050i(int value);

struct Flag02108dfc {
    unsigned char flag;
    unsigned char pad1;
    unsigned short value;
};

extern struct Flag02108dfc data_02108dfc;
extern unsigned char data_020f0dc8;

// KEEP-NAME
// USA: func_020758a8
ARM void InitBattleModeAndCommit020758a8(void) {
    int id;

    InitializeCardReading();
    SetReadContextPriority(8);

    id = GenerateLockOwnerID();
    if (id == -3) {
        func_020c9be0();
    }

    data_02108dfc.value = (unsigned short)id;
    SelectBattleContextMode2((int)data_02108dfc.value);
    DispatchCartridgeReadToArm7((void*)0x1001);
    _Z24PrepareAndCommit020d0050i((int)data_02108dfc.value);
    data_020f0dc8 = 1;
}
