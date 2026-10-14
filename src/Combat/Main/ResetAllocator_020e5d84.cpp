#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct SafeAllocator;
void ResetAndReturnAllocator_020466d0(struct SafeAllocator* obj);

extern struct SafeAllocator data_0210783c;

// USA: func_020e5d84
extern "C" __declspec(initcode) ARM void __sinit_020e5d84(void) {
    ResetAndReturnAllocator_020466d0(&data_0210783c);
}
