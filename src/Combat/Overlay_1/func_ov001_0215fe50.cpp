#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(int idx);
extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_0219b43c(void* mgr, int a, EventVec3* pos, int b, int c);

// USA: func_ov001_0215fe50
extern "C" ARM int func_ov001_0215fe50(void* self, int mode) {
    int id = func_ov017_021d60f4(self);
    void* p = (char*)self + 0x8;
    self = (char*)self + 0x10;
    int b;
    int c;
    int a = func_ov017_021d60f4(p);
    char* ptr = (char*)func_ov001_0215ab20(id);
    if (!ptr) {
        return 0;
    }
    EventVec3 v = *(EventVec3*)(ptr + 0x74);
    b = 0;
    c = 0;
    if (mode >= 3) {
        b = func_ov017_021d60f4(self);
        self = (char*)self + 0x8;
    }
    if (mode >= 4) {
        c = func_ov017_021d60f4(self);
    }
    func_ov017_0219b43c(func_ov017_0218b5b0(), a, &v, b, c);
    return 1;
}
