#include <globaldefs.h>

extern "C" int func_020d217c(int type, int a, int b, int c, int d);

// USA: func_020d2084
ARM void PostEvent0x1E_020d2084(int a, int b) {
    func_020d217c(0x1e, a, b, 0, 0);
}
