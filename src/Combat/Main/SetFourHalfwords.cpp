#include <globaldefs.h>

struct Struct0204408c {
    short x;
    short y;
    short z;
    short w;
};

#if defined(jpn)
#define SetFourHalfwords func_02044854
extern "C" ARM void func_02044854(struct Struct0204408c* s, short x, short y, short z, short w);
#endif

// USA: func_0204408c
ARM void SetFourHalfwords(struct Struct0204408c* s, short x, short y, short z, short w) {
    s->x = x;
    s->y = y;
    s->z = z;
    s->w = w;
}
