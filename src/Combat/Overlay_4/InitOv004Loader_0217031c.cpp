#include <globaldefs.h>

#pragma define_section initcode ".init" RX

void* DoResetInitOrder_021633e4(void* obj);
void* DoInitResetOrder_02163408(void* obj);
extern "C" void __register_global_object(void*, void*, void*);

extern int data_ov004_021708c8;
extern int data_ov004_0217082c;

// USA: func_ov004_0217031c  (semantic: InitOv004Loader_0217031c)
extern "C" __declspec(initcode) ARM void __sinit_ov004_0217031c(void) {
    DoResetInitOrder_021633e4(&data_ov004_021708c8);
    __register_global_object(&data_ov004_021708c8, (void*)DoInitResetOrder_02163408, &data_ov004_0217082c);
}
