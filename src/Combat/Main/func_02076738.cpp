#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02076738 {
    char pad[0x5e];
    unsigned char f5e;
};

// USA: func_02076738
extern "C" ARM unsigned int func_02076738(Struct02076738* s, unsigned char* p) {
    int v;
    unsigned int m1;
    int sh;
    unsigned int total;
    unsigned short i;
    unsigned int j;
    unsigned short nOut;
    unsigned short xa;
    unsigned short x8;
    unsigned short v3;
    unsigned short v2;
    unsigned short v1;
    unsigned short v0;
    unsigned int nIn;
    unsigned int nRow;
    unsigned int step;

    if (s->f5e == 0) {
        v = *(volatile int*)0x04000000 & 0x00300010;
    } else {
        v = *(volatile int*)0x04001000 & 0x00300010;
    }
    switch (v) {
        case 0: return 0;
        case 0x10: sh = 5; break;
        case 0x00100010: sh = 6; break;
        case 0x00200010: sh = 7; break;
        case 0x00300010: sh = 8; break;
        default: return 0;
    }
    nOut = 0;
    nIn = 0;
    memcpy(&nOut, p, 2);
    memcpy(&nIn, p + 2, 2);
    total = 0;
    i = 0;
    p += 4;
    while (i < nOut) {
        memcpy(&xa, p, 2);
        memcpy(&x8, p + 2, 2);
        memcpy(&nRow, p + 4, 4);
        m1 = (1 << sh) - 1;
        p += 8;
        j = 0;
        while (j < nRow) {
            memcpy(&v3, p, 2);
            memcpy(&v2, p + 2, 2);
            memcpy(&v1, p + 4, 2);
            memcpy(&v0, p + 6, 2);
            p += 8;
            step = (8 << v1) * (8 << v0);
            if (nIn == 3) {
                step >>= 1;
            }
            p += step;
            total += (step + m1) & ~m1;
            j++;
        }
        i++;
    }
    return total;
}