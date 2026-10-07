#include <globaldefs.h>

#include "Resource/Script.h"

struct Elem02072560 {
    short f0;
    short f2;
    short v[18];
    unsigned short f28;
    unsigned char f2a;
    unsigned char f2b;
};

struct List02072560 {
    struct Elem02072560* entries;
    short capacity;
    short count;
};

struct Session02072398 {
    int f0;
    struct List02072560* list;
};

extern "C" void _Z27AppendElementCapped02072560P12List02072560P12Elem02072560(struct List02072560* list, struct Elem02072560* src);

extern Session02072398 data_02108da8;

// USA: func_02072398
extern "C" ARM int func_02072398(Script::Parameter* params, int count) {
    struct Elem02072560 e;
    e.f0 = -1;
    e.f2 = -1;
    unsigned char i = 0;
    while (i < 18) {
        e.v[i] = -1;
        i++;
    }
    e.f28 = 100;
    e.f2a = 0;
    e.f0 = (params++)->ToInt();
    e.f2 = (params++)->ToInt();
    count -= 2;
    for (int j = 0; j < 18; j++) {
        e.v[j] = params[0].ToInt();
        params++;
        count--;
    }
    if (count != 0) {
        e.f28 = params[0].ToInt();
        params++;
        count--;
    }
    if (count != 0) {
        e.f2a = params[0].ToInt();
    }
    _Z27AppendElementCapped02072560P12List02072560P12Elem02072560(data_02108da8.list, &e);
    return 1;
}
