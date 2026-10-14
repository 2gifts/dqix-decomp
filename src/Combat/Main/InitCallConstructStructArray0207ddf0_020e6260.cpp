#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct _Z18InitStruct0207d7c0P12Init0207d7c0;
struct Init0207d7c0;
ARM void* ConstructStructArray0207ddf0(Init0207d7c0*);
extern "C" ARM void* _Z28ConstructStructArray0207de1cP12Init0207d7c0(struct _Z18InitStruct0207d7c0P12Init0207d7c0* obj);

extern "C" void __register_global_object(int c, int b, void* node);

extern _Z18InitStruct0207d7c0P12Init0207d7c0 data_02108ea8;
extern int data_02108e9c;

// USA: func_020e6260
extern "C" __declspec(initcode) ARM void __sinit_020e6260(void) {
    ConstructStructArray0207ddf0((Init0207d7c0*)&data_02108ea8);
    __register_global_object((int)&data_02108ea8, (int)_Z28ConstructStructArray0207de1cP12Init0207d7c0, &data_02108e9c);
}
