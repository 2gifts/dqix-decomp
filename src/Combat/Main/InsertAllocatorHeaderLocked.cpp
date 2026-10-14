#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

extern SignedAllocatorList data_021103bc;

// USA: func_020bf458
ARM void InsertAllocatorHeaderLocked_020bf458(SignedAllocatorHeader* header) {
    unsigned int mask = DisableIRQInterrupts();
    data_021103bc.InsertAtEnd(header);
    SetIRQInterruptState(mask);
}
