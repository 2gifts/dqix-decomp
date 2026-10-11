#include <globaldefs.h>
#include "System/OverlayId.h"

#if defined(jpn)
#define func_ov023_021d8a40 func_ov030_021d9300
#define func_ov024_021d92f0 func_ov030_021d9bb0
#endif

extern "C" void func_020a1940(unsigned int id);
extern "C" int func_020a1bb4(unsigned int id);
extern "C" void* func_ov023_021d8a40(void* data, int* out);
extern "C" void func_ov017_0218b688(void* obj);
extern "C" void func_ov024_021d92f0(void* obj, void* data, int* out);
extern char data_02114e20;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020d6cb4
ARM void GuardedOverlayDispatch020d6cb4() {
    unsigned int id = OVERLAY_ID(30);
    int result = 0;
    func_020a1940(id);
    void* obj = func_ov023_021d8a40(&data_02114e20, &result);
    func_020a1bb4(id);
    func_ov017_0218b688(obj);
    func_020a1940(id);
    func_ov024_021d92f0(obj, &data_02114e20, &result);
    func_020a1bb4(id);
}

// JPN: 0x020d86bc
