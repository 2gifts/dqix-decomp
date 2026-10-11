#include <globaldefs.h>

struct Vec020311e8 {
    int x;
    int y;
    int z;
};

struct Dst02031188 {
    Vec020311e8 v0;
    Vec020311e8 v1;
    Vec020311e8 v2;
    Vec020311e8 v3;
};

struct Src02031188 {
    short s[12];
};

extern "C" ARM void func_020311e8(Vec020311e8* v, int x, int y, int z);

// USA: func_02031188
extern "C" ARM void func_02031188(Dst02031188* d, Src02031188* s) {
    func_020311e8(&d->v3, s->s[9], s->s[10], s->s[11]);
    func_020311e8(&d->v0, s->s[0], s->s[1], s->s[2]);
    func_020311e8(&d->v1, s->s[3], s->s[4], s->s[5]);
    func_020311e8(&d->v2, s->s[6], s->s[7], s->s[8]);
}
