#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" double _dflt(int);
extern "C" double _ddiv(double, double);
extern "C" double func_0200b0f0(double, double);
extern "C" int func_0200af44(double);

// USA: func_020323c4
extern "C" ARM int func_020323c4(int min, int max) {
    int r = rand();
    double span = max + 1 - min;
    double q = _ddiv(_dflt(r - 1), 32767.0);
    return min + func_0200af44(func_0200b0f0(span, q));
}