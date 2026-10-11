#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue5A4_5A0 = 0x5a0 };
#else
enum { kRegionValue5A4_5A0 = 0x5a4 };
#endif


int GetGlobal02109400(void);
int AlwaysTrue02094b4c(void);
extern "C" void _Z21BlankFunction02094b34v(int, int, int, int, int);

struct Struct5a4_021685dc { char pad[kRegionValue5A4_5A0]; unsigned char state; unsigned char step; };

// USA: func_ov003_021685dc  (semantic: RunPendingEvent_021685dc)
// JPN: func_ov003_02168464
extern "C" ARM void func_ov003_021685dc(Struct5a4_021685dc* obj) {
    if (obj->state == 0) return;
    if (obj->step == 0) {
        int g = GetGlobal02109400();
        _Z21BlankFunction02094b34v(g, 0x1f5, 0x66, 0, 0);
        obj->step = obj->step + 1;
    } else if (obj->step == 1) {
        GetGlobal02109400();
        if (AlwaysTrue02094b4c() != 0) {
            obj->state = 0;
            obj->step = 0;
        }
    }
}
