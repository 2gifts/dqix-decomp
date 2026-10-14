#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct ResetObj020d7a5c;
void ResetAndReturnArg020d806c(struct ResetObj020d7a5c* obj);

extern struct ResetObj020d7a5c data_0214e34c;

// USA: func_020e66fc
extern "C" __declspec(initcode) ARM void __sinit_020e66fc(void) {
    ResetAndReturnArg020d806c(&data_0214e34c);
}
