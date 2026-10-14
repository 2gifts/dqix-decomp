#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct _Z18InitStruct0207d7c0P12Init0207d7c0;
struct Init0207d7c0;
ARM void* ConstructStructArray0207ddf0(Init0207d7c0*);
ARM void* ConstructStructArray0207de1c(Init0207d7c0*);

extern "C" void __register_global_object(int c, int b, void* node);

extern _Z18InitStruct0207d7c0P12Init0207d7c0 data_02108ea8;
extern int data_02108e9c;

// USA: func_020e6260
extern "C" __declspec(initcode) ARM void __sinit_020e6260(void) {
    ConstructStructArray0207ddf0((Init0207d7c0*)&data_02108ea8);
    __register_global_object((int)&data_02108ea8, (int)ConstructStructArray0207de1c, &data_02108e9c);
}
