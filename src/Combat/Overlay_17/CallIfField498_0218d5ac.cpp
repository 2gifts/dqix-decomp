#include <globaldefs.h>

extern "C" void func_020dbdc0(void* p);

// JPN: func_ov017_0218e18c
// USA: func_ov017_0218d5ac
ARM void CallIfField498_0218d5ac(void* obj) {
    void* p = *(void**)((char*)obj
#if defined(jpn)
 + 0x41e8
#else
 + 0x4498
#endif
);
    if (p) func_020dbdc0(p);
}
