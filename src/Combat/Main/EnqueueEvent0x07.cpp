#include <globaldefs.h>

extern "C" int func_020d217c(int, int, int, int, int);

// USA: func_020d2154
ARM int EnqueueEvent0x07_020d2154(int a, int b, int c, int d, int e) {
    return func_020d217c(0x7, a | (e << 24), b, c, d);
}
