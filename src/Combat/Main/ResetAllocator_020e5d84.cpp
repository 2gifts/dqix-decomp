#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct SafeAllocator;
void ResetAndReturnAllocator(struct SafeAllocator* obj);

extern struct SafeAllocator data_0210783c;

// USA: func_020e5d84
extern "C" __declspec(initcode) ARM void __sinit_020e5d84(void) {
    ResetAndReturnAllocator(&data_0210783c);
}
