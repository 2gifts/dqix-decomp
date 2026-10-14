#include <globaldefs.h>

extern "C" int func_020d217c(int type, int a, int b, int c, int d);

// USA: func_020d20a4
ARM void PostEvent0x1F_020d20a4(int a, int b) {
    func_020d217c(0x1f, a, b, 0, 0);
}
