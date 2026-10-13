#include <globaldefs.h>
#pragma optimize_for_size off

struct Table0221ef80 {
    int pad0[2];
    int field8;
    int pad2[3];
    int field18;
};

extern Table0221ef80 data_ov031_0224f620;
extern "C" int func_ov031_0220cae0(int a0, int a1);
int DispatchOnZeroPair_0220cdd4(int a, int b, int c);
extern "C" int func_ov031_0220d214(void);
extern "C" void func_ov031_0221ecc8(void);

// USA: func_ov031_0221ef80
extern "C" THUMB int func_ov031_0221ef80(void) {
    switch (data_ov031_0224f620.field18) {
    case 5:
        if (DispatchOnZeroPair_0220cdd4(0, 0, 0) == 3) goto success;
        return 0;
    case 7:
        if (func_ov031_0220d214() == 3) goto success;
        return 0;
    case 1:
        if (func_ov031_0220cae0(data_ov031_0224f620.field8, (int)func_ov031_0221ecc8) == 3) goto success;
        return 0;
    case 0:
    case 2:
    case 3:
    case 4:
    case 6:
    case 8:
    default:
        return 0;
    }
success:
    return 1;
}
