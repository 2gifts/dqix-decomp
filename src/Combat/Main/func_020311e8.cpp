#include <globaldefs.h>

struct Vec020311e8 {
    int x;
    int y;
    int z;
};

// USA: func_020311e8
extern "C" ARM void func_020311e8(Vec020311e8* v, int x, int y, int z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
