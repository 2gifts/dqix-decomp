#include <globaldefs.h>

extern "C" unsigned int _ZN13SafeAllocator21ResetAllocatorPointerEv();
extern "C" unsigned int func_02029568(void*);

struct Trans_0218b5a0
{
    char unk_0[0x14];
    char menu[0x80];
    unsigned int unk_94;
};

// USA: func_ov016_0218b5a0  (semantic: Trans_0218b5a0)
extern "C" ARM unsigned int func_ov016_0218b5a0(Trans_0218b5a0* self) {
    _ZN13SafeAllocator21ResetAllocatorPointerEv();
    func_02029568(self->menu);
    self->unk_94 = 1;
    return 1;
}
