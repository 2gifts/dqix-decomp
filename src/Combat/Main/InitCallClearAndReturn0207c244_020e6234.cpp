#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" ARM char* _ZN24LootableContainerManagerC1Ev(char* obj);
ARM char* ClearRegionAndReturnSelf020269d0(char* obj);

extern "C" void __register_global_object(int c, int b, void* node);

extern char data_02108e90;
extern int data_02108e84;

// USA: func_020e6234
extern "C" __declspec(initcode) ARM void __sinit_020e6234(void) {
    _ZN24LootableContainerManagerC1Ev(&data_02108e90);
    __register_global_object((int)&data_02108e90, (int)ClearRegionAndReturnSelf020269d0, &data_02108e84);
}
