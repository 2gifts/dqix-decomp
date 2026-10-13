#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
enum { kRegionValue5A4_5A0 = 0x5a0 };
#else
enum { kRegionValue5A4_5A0 = 0x5a4 };
#endif



struct Struct5a4_021685dc { char pad[kRegionValue5A4_5A0]; unsigned char state; unsigned char step; };

// USA: func_ov003_021685dc  (semantic: RunPendingEvent_021685dc)
extern "C" ARM void func_ov003_021685dc(Struct5a4_021685dc* obj) {
    if (obj->state == 0) return;
    if (obj->step == 0) {
        FontBankLoader* g = GetGlobal02109400();
        BlankFunction02094b34(g, 0x1f5, 0x66, 0, 0);
        obj->step = obj->step + 1;
    } else if (obj->step == 1) {
        if (AlwaysTrue02094b4c(GetGlobal02109400()) != 0) {
            obj->state = 0;
            obj->step = 0;
        }
    }
}
