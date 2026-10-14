#include <globaldefs.h>

extern "C" int func_020ceba8(int a, int b, int c, int d);

// USA: func_020cedc0
ARM int DispatchIfEquals1_020cedc0(int a) {
    if (a != 1) a = 0;
    return func_020ceba8(a, 0, 0, 1);
}
