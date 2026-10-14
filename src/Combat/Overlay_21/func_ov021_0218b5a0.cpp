#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void _Z25InitializeBrightnessStateP13GameResources();

// USA: func_ov021_0218b5a0  (semantic: Trans_0218b5a0)
extern "C" ARM void func_ov021_0218b5a0(unsigned char* self) {
    _Z25InitializeBrightnessStateP13GameResources();
    ((SafeAllocator*)(self + 0x2c))->ResetAllocatorPointer();
    *(unsigned int*)(self + 0x40) = 0;
    *(unsigned int*)(self + 0xb8) = 0;
}
