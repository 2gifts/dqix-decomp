#include <globaldefs.h>
#include "System/OverlayId.h"

struct AllocatorUnion;

#if defined(jpn)
#define func_ov010_02184354 func_ov010_02185454
#define func_ov008_021842a0 func_ov010_021842a0
#endif
extern "C" int func_ov010_02184354(void* obj);
extern "C" void _Z30ForwardAndClearField8_021c2710Ph(unsigned char* self);
extern "C" void func_020a1940(unsigned int id);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020c9be0(void);
extern "C" void func_ov008_021842a0(void* obj);
extern char data_02114e20;

// USA: func_ov017_021c26ac
extern "C" ARM void func_ov017_021c26ac(unsigned char* self) {
    if (*(void**)(self + 8) != NULL) {
        if (func_ov010_02184354(*(void**)(self + 8)) == 0) {
            return;
        }
        _Z30ForwardAndClearField8_021c2710Ph(self);
        return;
    }
    func_020a1940(OVERLAY_ID(10));
    *(void**)(self + 8) = AllocateAligned4((AllocatorUnion*)&data_02114e20, 0x28);
    if (*(void**)(self + 8) == NULL) {
        func_020c9be0();
    }
    func_ov008_021842a0(*(void**)(self + 8));
}
