#include <globaldefs.h>
#include <System/DTCM.h>

extern "C" void SDK_IRQ_STACKSIZE();

// KEEP-NAME
// USA: func_020c6d48
ARM void StoreSharedMemMagicWords()
{
    *(unsigned int*)((unsigned long)&data_027e0000 + 0x3f80 - sizeof(unsigned int)) = STACK_BOTTOM_MAGIC;
    *(unsigned int*)((unsigned long)&data_027e0000 + 0x3f80 - (long)SDK_IRQ_STACKSIZE) = STACK_TOP_MAGIC;
}
