#include <globaldefs.h>

#pragma define_section initcode ".init" RX

void EmptyDestructor0205ec2c(void* obj);
void EmptyDestructor0205ec30(void* obj);
extern "C" void __register_global_object(int c, int b, void* node);

extern void* data_02108760;
extern void* data_02108754;

// USA: func_020e5ee0
extern "C" __declspec(initcode) ARM void __sinit_020e5ee0(void) {
    EmptyDestructor0205ec2c(&data_02108760);
    __register_global_object((int)&data_02108760, (int)EmptyDestructor0205ec30, &data_02108754);
}
