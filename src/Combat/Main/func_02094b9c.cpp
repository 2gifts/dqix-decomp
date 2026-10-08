#include <globaldefs.h>

struct Obj02094b9c {
    char pad00[0x08];
    int pos[3];
    int size[3];
    char pad20[0x02];
    short f22;
    int f24;
    int f28;
};

struct Bounds02094b9c {
    int v[6];
};

struct Shape02094b9c {
    int a;
    int b;
    int c;
    int d;
    int e;
};

extern "C" ARM int func_020321e0(void* anchor, struct Bounds02094b9c* b, short d, int* pos, int e);
extern "C" ARM int func_02032148(void* anchor, struct Shape02094b9c* s, int e);

// USA: func_02094b9c
extern "C" ARM int func_02094b9c(struct Obj02094b9c* p, void* anchor) {
    if (p->f28 & 8) {
        return 0;
    }

    struct Bounds02094b9c b;
    struct Shape02094b9c s;
    struct Bounds02094b9c t;

    t.v[0] = p->pos[0] + (p->size[0] >> 1);
    t.v[1] = p->pos[1] + (p->size[1] >> 1);
    t.v[2] = p->pos[2] + (p->size[2] >> 1);
    t.v[3] = p->pos[0] - (p->size[0] >> 1);
    t.v[4] = p->pos[1] - (p->size[1] >> 1);
    t.v[5] = p->pos[2] - (p->size[2] >> 1);

    b = t;

    int result = 0;
    int ret;
    int hasSize = p->size[2] > 0;
    if (hasSize) {
        ret = func_020321e0(anchor, &b, p->f22, &p->pos[0], p->f24);
    } else {
        s.a = p->pos[0];
        s.b = p->pos[1];
        s.c = p->pos[2];
        s.d = p->size[0];
        s.e = p->size[1];
        ret = func_02032148(anchor, &s, s.e);
    }
    if (ret) {
        result = 1;
    }

    int flags = p->f28;
    if (result != 0) {
        if (flags & 1) {
            if (flags & 4) {
                result = 0;
            } else {
                p->f28 = flags | 2;
            }
        }
    } else {
        if (flags & 1) {
            if (flags & 2) {
                p->f28 = flags | 4;
            }
        }
    }
    return result;
}