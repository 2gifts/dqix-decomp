#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct SafeAllocator;
void ResetAndReturnAllocator(struct SafeAllocator* alloc);

extern struct SafeAllocator data_ov031_02291e3c;

// USA: func_ov031_02249650  (semantic: ResetAllocator_02249650)
extern "C" __declspec(initcode) ARM void __sinit_ov031_02249650(void) {
    ResetAndReturnAllocator(&data_ov031_02291e3c);
}
