#include <globaldefs.h>

extern "C" int func_020d217c(int type, int a, int b, int c, int d);

// USA: func_020d20c4
ARM void PostEvent0x20_020d20c4(int a, int b) {
    func_020d217c(0x20, a, b, 0, 0);
}
