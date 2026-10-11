#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" double _dflt(int);
extern "C" double _ddiv(double, double);
extern "C" double func_0200b0f0(double, double);
extern "C" int func_0200af44(double);

// USA: func_02032370
extern "C" ARM int func_02032370(int span) {
    int r = rand();
    double dspan = _dflt(span);
    double q = _ddiv(_dflt(r - 1), 32767.0);
    return func_0200af44(func_0200b0f0(dspan, q));
}
