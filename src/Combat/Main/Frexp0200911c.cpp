#include <globaldefs.h>

extern "C" double _dmul(double a, double b);

// USA: func_0200911c  (semantic: Frexp0200911c)
#pragma optimize_for_size off
extern "C" ARM double func_0200911c(double value, int* exp, int pad) {
    int hi = ((int*)&value)[1];
    int lo = ((int*)&value)[0];
    int absHi = hi & 0x7fffffff;
    *exp = 0;

    if (absHi >= 0x7ff00000 || (absHi | lo) == 0) {
        return value;
    }

    if (absHi < 0x100000) {
        value = _dmul(value, 18014398509481984.0);
        *exp = -0x36;
        hi = ((int*)&value)[1];
        absHi = hi & 0x7fffffff;
    }

    *exp += -0x3fe + (absHi >> 20);
    ((int*)&value)[1] = (hi & 0x800fffff) | 0x3fe00000;
    return value;
}
