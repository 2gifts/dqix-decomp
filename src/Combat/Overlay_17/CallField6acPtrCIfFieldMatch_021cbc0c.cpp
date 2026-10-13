#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void* func_ov017_021b8478(void* obj);
void CallField6acPtrC_021b86e0(void* obj);

struct Src021cbc0c { unsigned char pad[4]; unsigned short field4; };
struct Ret021cbc0c { unsigned char pad[8]; unsigned short field8; };

// USA: func_ov017_021cbc0c
ARM void CallField6acPtrCIfFieldMatch_021cbc0c(int unused0, Src021cbc0c* src, int unused2, unsigned char* obj) {
    void* work = ((GameResources*)obj)->unknown_ptr_3718;
    Ret021cbc0c* r = (Ret021cbc0c*)func_ov017_021b8478(work);
    if (!r) return;
    if (r->field8 != src->field4) return;
    CallField6acPtrC_021b86e0(work);
}
