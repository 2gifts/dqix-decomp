#include <globaldefs.h>

extern "C" int func_020d217c(int type, int a, int b, int c, int d);

// USA: func_020d2018
ARM void PostEvent0x15_020d2018(int a, int b) {
    func_020d217c(0x15, a, b, 0, 0);
}
