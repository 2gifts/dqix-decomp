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
extern "C" void _Z29SetField16IfMinusOne_02222e20i(int);
extern "C" int _Z32CheckMaskAgainstField32_0223d354i(int);
extern "C" int func_ov031_0223d394(int);
extern "C" void func_ov031_022296b8(int);
extern "C" void func_ov031_022237dc(int, int, int, int);

// USA: func_ov031_0222938c
extern "C" ARM void func_ov031_0222938c() {
    unsigned int index = 0;
    RangeParam_0223d49c* range = data_ov031_02248dfa;
    do {
        if (func_ov031_0223d49c(range)) {
            _Z29SetField16IfMinusOne_02222e20i(1);
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
    if (_Z32CheckMaskAgainstField32_0223d354i(1)) {
        _Z29SetField16IfMinusOne_02222e20i(1);
        return;
    }
    if (_Z32CheckMaskAgainstField32_0223d354i(2)) {
        _Z29SetField16IfMinusOne_02222e20i(0);
        return;
    }
    if (func_ov031_0223d394(0x40)) {
        func_ov031_022296b8(1);
        return;
    }
    if (func_ov031_0223d394(0x80)) func_ov031_022296b8(3);
}
