#include <globaldefs.h>

struct RangeParam_0223d49c { unsigned short f0, f1, f2, f3; };
struct SelectionColumn_0222938c { unsigned short value; unsigned short padding[3]; };
extern RangeParam_0223d49c data_ov031_02248dfa[3];
extern SelectionColumn_0222938c data_ov031_02248e12[];
extern SelectionColumn_0222938c data_ov031_02248e16[];
extern SelectionColumn_0222938c data_ov031_02248e14[];
extern SelectionColumn_0222938c data_ov031_02248e18[];
extern signed char data_ov031_02290c5c;
extern "C" int func_ov031_0223d49c(RangeParam_0223d49c*);
void SetField16IfMinusOne_02222e20(int);
int CheckMaskAgainstField32_0223d354(int);
extern "C" int func_ov031_0223d394(int);
extern "C" void func_ov031_022296b8(int);
extern "C" void func_ov031_022237dc(int, int, int, int);

// USA: func_ov031_0222938c
extern "C" ARM void func_ov031_0222938c() {
    unsigned int index = 0;
    RangeParam_0223d49c* range = data_ov031_02248dfa;
    do {
        if (func_ov031_0223d49c(range)) {
            SetField16IfMinusOne_02222e20(1);
            unsigned char selected = index;
            unsigned short first = data_ov031_02248e12[selected].value;
            unsigned short second = data_ov031_02248e16[selected].value;
            unsigned short third = data_ov031_02248e14[selected].value;
            unsigned short fourth = data_ov031_02248e18[selected].value;
            data_ov031_02290c5c = index;
            func_ov031_022237dc(first, second, third, fourth);
            return;
        }
        ++index;
        ++range;
    } while (index < 3);
    if (CheckMaskAgainstField32_0223d354(1)) {
        SetField16IfMinusOne_02222e20(1);
        return;
    }
    if (CheckMaskAgainstField32_0223d354(2)) {
        SetField16IfMinusOne_02222e20(0);
        return;
    }
    if (func_ov031_0223d394(0x40)) {
        func_ov031_022296b8(1);
        return;
    }
    if (func_ov031_0223d394(0x80)) func_ov031_022296b8(3);
}
