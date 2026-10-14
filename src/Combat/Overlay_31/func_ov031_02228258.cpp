#include <globaldefs.h>

struct RangeParam_0223d49c { unsigned short left, top, right, bottom; };
extern RangeParam_0223d49c data_ov031_02248d8e[2];
extern unsigned short data_ov031_02248d9e[];
extern unsigned short data_ov031_02248da2[];
extern unsigned short data_ov031_02248da0[];
extern unsigned short data_ov031_02248da4[];
extern signed char data_ov031_02290c50;
extern "C" int func_ov031_0223d49c(RangeParam_0223d49c*);
void SetField16IfMinusOne_02222e20(int);
int CheckMaskAgainstField32_0223d354(int);
extern "C" int func_ov031_0223d394(int);
extern "C" void func_ov031_022237dc(unsigned short, unsigned short, unsigned short, unsigned short);
extern "C" void func_ov031_022284ec(int);

// USA: func_ov031_02228258
extern "C" ARM void func_ov031_02228258() {
    int i = 0;
    RangeParam_0223d49c* range = data_ov031_02248d8e;
    do {
        if (func_ov031_0223d49c(range)) {
            SetField16IfMinusOne_02222e20(1);
            int index = (unsigned char)i * 4;
            unsigned short left = data_ov031_02248d9e[index];
            unsigned short top = data_ov031_02248da2[index];
            unsigned short right = data_ov031_02248da0[index];
            unsigned short bottom = data_ov031_02248da4[index];
            data_ov031_02290c50 = i;
            func_ov031_022237dc(left, top, right, bottom);
            return;
        }
        i++;
        range++;
    } while ((unsigned int)i < 2);
    if (CheckMaskAgainstField32_0223d354(1)) { SetField16IfMinusOne_02222e20(1); return; }
    if (CheckMaskAgainstField32_0223d354(2)) { SetField16IfMinusOne_02222e20(0); return; }
    if (func_ov031_0223d394(0x40)) { func_ov031_022284ec(1); return; }
    if (func_ov031_0223d394(0x80)) { func_ov031_022284ec(3); return; }
    if (func_ov031_0223d394(0x20)) { func_ov031_022284ec(0); return; }
    if (func_ov031_0223d394(0x10)) func_ov031_022284ec(2);
}
