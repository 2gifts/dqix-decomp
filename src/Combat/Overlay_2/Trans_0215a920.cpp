#include <globaldefs.h>

struct Trans {
    unsigned char f0;
    unsigned int f4;
    int f8;
};

// USA: func_ov002_0215a920  (semantic: Trans_0215a920)
extern "C" ARM Trans* func_ov002_0215a920(Trans* t) {
    t->f0 = 0;
    t->f4 = 0;
    t->f8 = -1;
    return t;
}
