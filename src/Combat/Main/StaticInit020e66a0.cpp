#include <globaldefs.h>
#pragma define_section initcode ".init" RX

void BlankFunction02012298(void*);
extern "C" void _Z21BlankFunction0201238cv(void);
void BlankFunction02012530(void*);
extern "C" void _Z17EmptyStub02012534v(void);
extern "C" void _Z22ClearField0x0_02046724Pi(int* field);
extern "C" int __register_global_object(void*, void*, void*);

extern int data_02114e30;
extern int data_02114e14;
extern int data_02114e54;
extern int data_02114e08;
extern int data_02114e04;

// USA: func_020e66a0
extern "C" __declspec(initcode) ARM void __sinit_020e66a0(void) {
    BlankFunction02012298(&data_02114e30);
    __register_global_object(&data_02114e30, (void*)_Z21BlankFunction0201238cv, &data_02114e14);
    BlankFunction02012530(&data_02114e54);
    __register_global_object(&data_02114e54, (void*)_Z17EmptyStub02012534v, &data_02114e08);
    _Z22ClearField0x0_02046724Pi(&data_02114e04);
}
