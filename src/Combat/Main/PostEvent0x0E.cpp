#include <globaldefs.h>

extern "C" int func_020d217c(int type, int a, int b, int c, int d);

// USA: func_020d2038
ARM void PostEvent0x0E_020d2038(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9) {
    func_020d217c(0xe,
        p0 | (p8 << 16),
        p2,
        p5 | ((p6 << 24) | (p7 << 22)),
        p4 | (((p3 << 26) | (p1 << 24)) | (p9 << 16)));
}
