#include <globaldefs.h>

#pragma define_section initcode ".init" RX

void InitObjectTables0208b508(void* obj);

extern char data_02108f0c;

// USA: func_020e628c
extern "C" __declspec(initcode) ARM void __sinit_020e628c(void) {
    InitObjectTables0208b508(&data_02108f0c);
}
