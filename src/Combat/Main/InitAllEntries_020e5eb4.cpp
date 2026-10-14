#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Obj02058704;
void InitAllEntries02058704(Obj02058704*);
void RunAndReturnArg0205873c(void* obj);
extern "C" void __register_global_object(int c, int b, void* node);

extern void* data_021079ec;
extern void* data_021079e0;

// USA: func_020e5eb4
extern "C" __declspec(initcode) ARM void __sinit_020e5eb4(void) {
    InitAllEntries02058704((Obj02058704*)&data_021079ec);
    __register_global_object((int)&data_021079ec, (int)RunAndReturnArg0205873c, &data_021079e0);
}
