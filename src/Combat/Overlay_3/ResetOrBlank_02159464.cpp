#include <globaldefs.h>



int GetGlobal02109400(void);
int AlwaysTrue02094b4c(void);
extern "C" void _Z21BlankFunction02094b30v(int, int, int);

// USA: func_ov003_02159464  (semantic: ResetOrBlank_02159464)
// JPN: func_ov003_0215a930
extern "C" ARM void func_ov003_02159464(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    int g;
    unsigned char state;
    if (o[0x59d] == 0) return;
    g = GetGlobal02109400();
    state = o[0x59e];
    if (state == 0) {
        _Z21BlankFunction02094b30v(g, 0x200, 1);
        o[0x59e] = o[0x59e] + 1;
        return;
    }
    if (state != 1) return;
    if (AlwaysTrue02094b4c() != 0) {
        o[0x59d] = 0;
        o[0x59e] = 0;
    }
}
