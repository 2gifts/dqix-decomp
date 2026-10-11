#include <globaldefs.h>

struct Elem0205b008 {
    unsigned short f0;
    unsigned short f1;
    unsigned short f2;
};

struct Arr0205b008 {
    unsigned short count;
    unsigned short field_2;
    struct Elem0205b008* arr;
};

// USA: func_0205b008
extern "C" ARM int func_0205b008(int a, struct Arr0205b008* b, unsigned int c, int d,
                                 unsigned short e, int f) {
    unsigned short i;
    unsigned short shift;
    struct Elem0205b008* p;
    unsigned int v;

    if (b == 0) {
        return 1;
    }
    if (c >= 3) {
        return 1;
    }
    if (b == 0) {
        return 1;
    }
    shift = e;
    for (i = 0; i < b->count; i++) {
        p = b->arr + i;
        switch (c) {
        case 0:
            v = p->f0;
            break;
        case 1:
            v = p->f1;
            break;
        case 2:
            v = p->f2;
            break;
        }
        v = (unsigned short)(v & (unsigned int)~d) | ((((unsigned int)(f << shift)) << 16) >> 16);
        switch (c) {
        case 0:
            p->f0 = v;
            break;
        case 1:
            p->f1 = v;
            break;
        case 2:
            p->f2 = v;
            break;
        }
    }
    return 0;
}
