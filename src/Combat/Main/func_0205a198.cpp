#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct0205a198 {
    char pad0[8];
    unsigned int f08;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned short f1c;
    unsigned short f1e;
    unsigned short f20;
    unsigned char f22;
    unsigned char f23;
    unsigned char f24;
    unsigned char f25;
    signed char f26;
    char pad1[1];
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0205a198
void Init0205a198(Struct0205a198 *p) {
    memset(p, 0, 8);
    p->f08 = 0;
    p->f0c = p->f10 = 0x1000;
    p->f14 = p->f18 = 0;
    p->f1c = 0;
    p->f1e = 0;
    p->f20 = 0;
    p->f22 = 0;
    p->f23 = 0;
    p->f24 = 0;
    int d = p->f24 - 1;
    p->f25 = d;
    p->f26 = d;
}
