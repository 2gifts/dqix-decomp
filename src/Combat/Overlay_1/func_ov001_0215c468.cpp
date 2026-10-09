#include <globaldefs.h>
#include "Combat/Overlay_1/EventArgs.h"

extern "C" float func_ov017_021d6110(void*);
extern "C" void* func_ov017_021d60f4(void*);
extern "C" void* func_ov001_0215ab20(void*);
extern "C" void* _Z26EnqueueEventType5_0215a3f8Pviii(void* ctx, EventVec3 v);

// USA: func_ov001_0215c468
extern "C" ARM int func_ov001_0215c468(void* self) {
    void* node = func_ov001_0215ab20(func_ov017_021d60f4(self));
    if (node == NULL) {
        return 0;
    }
    EventVec3 v;
    v.a = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x8));
    v.b = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x10));
    v.c = (int)(4096.0f * func_ov017_021d6110((char*)self + 0x18));
    _Z26EnqueueEventType5_0215a3f8Pviii(node, v);
    return 1;
}
