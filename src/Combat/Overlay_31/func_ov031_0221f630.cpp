#include <globaldefs.h>

struct State0221f630 {
    char pad0[8];
    int handle;
    char pad0c[0x20];
    unsigned int state;
};
extern State0221f630 data_ov031_0224f670;
int DispatchOnZeroPair_0220cdd4(int, int, int);
extern "C" int func_ov031_0220d214();
extern "C" void func_ov031_0221f324();
extern "C" int func_ov031_0220cae0(int, void (*)());

// USA: func_ov031_0221f630
extern "C" THUMB int func_ov031_0221f630() {
    switch (data_ov031_0224f670.state) {
    case 5:
        if (DispatchOnZeroPair_0220cdd4(0, 0, 0) != 3) return 0;
        break;
    case 7:
        if (func_ov031_0220d214() != 3) return 0;
        break;
    case 1:
        if (func_ov031_0220cae0(data_ov031_0224f670.handle, func_ov031_0221f324) != 3) return 0;
        break;
    default:
    case 0:
    case 2:
    case 3:
    case 4:
    case 6:
    case 8:
        return 0;
    }
    return 1;
}
