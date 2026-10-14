#include <globaldefs.h>
#include "Graphics/itcm/VRAMStaging.h"

void EnableInstructionTcm(void);
void EnableDataTcm(void);

struct ClearFields0And8And0x20Struct;
void ClearFields0And8And0x20(struct ClearFields0And8And0x20Struct* p);

extern "C" void func_020c93d0(void*, int, int, void*, void*);
void SendStagedVRAMDataToVRAM(void*);

extern unsigned int g_stagingManagerInstance[];
extern int data_0214e5bc;

// USA: func_020dc034
ARM void InitStreamAndRegisterHandler0xC0(void) {
    EnableInstructionTcm();
    EnableDataTcm();
    ((VRAMStagingManager*)g_stagingManagerInstance)->ZeroInitialize();
    ClearFields0And8And0x20((struct ClearFields0And8And0x20Struct*)&data_0214e5bc);
    func_020c93d0(&data_0214e5bc, 0xc0, 0xf, (void*)SendStagedVRAMDataToVRAM, g_stagingManagerInstance);
}
