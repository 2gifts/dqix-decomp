#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

#pragma define_section initcode ".init" RX

void ClearFourRegions02079fc8(char*);
void ClearFourRegions0207a014(char*);
extern "C" void __register_global_object(int c, int b, void* node);

extern ActionDataTables data_02108e10;
extern void* data_02108e04;

// USA: func_020e60f8
extern "C" __declspec(initcode) ARM void __sinit_020e60f8(void) {
    ClearFourRegions02079fc8((char*)&data_02108e10);
    __register_global_object((int)&data_02108e10, (int)ClearFourRegions0207a014, &data_02108e04);
}
