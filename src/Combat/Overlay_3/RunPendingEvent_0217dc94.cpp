#include <globaldefs.h>



int GetGlobal02109400(void);
int AlwaysTrue02094b4c(void);
extern "C" void _Z21BlankFunction02094b34v(int, int, int, int, int);

struct Struct6_0217dc94 { char pad[0x6]; signed char step; char pad2; unsigned short field8; };

// USA: func_ov003_0217dc94  (semantic: RunPendingEvent_0217dc94)
// JPN: func_ov003_0217c918
extern "C" ARM void func_ov003_0217dc94(Struct6_0217dc94* obj) {
    if ((obj->field8 & 1) == 0) return;
    if (obj->step == 0) {
        int g = GetGlobal02109400();
        _Z21BlankFunction02094b34v(g, 0x1f5, 0x66, 0, 0);
        obj->step = 1;
    } else if (obj->step == 1) {
        GetGlobal02109400();
        if (AlwaysTrue02094b4c() != 0) {
            obj->field8 = obj->field8 & ~1;
            obj->step = -1;
        }
    }
}
