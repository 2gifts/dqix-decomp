#include <globaldefs.h>

extern "C" void func_020c9be0(void);
extern short data_0211214c;

#pragma optimize_for_size off
// USA: func_020d18a4
ARM void HandleMsg1SetFlag_020d18a4(int a, int msg) {
    if ((msg & 0x3f) == 1) {
        data_0211214c = 1;
    } else {
        func_020c9be0();
    }
}
