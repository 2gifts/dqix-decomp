#include <globaldefs.h>

#pragma define_section initcode ".init" RX

void ResetAndReturnSelf0208e870(char* obj);

extern char data_02108fe4;

// USA: func_020e62a0
extern "C" __declspec(initcode) ARM void __sinit_020e62a0(void) {
    ResetAndReturnSelf0208e870(&data_02108fe4);
}
