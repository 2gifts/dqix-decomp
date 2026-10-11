#include <globaldefs.h>

// USA: func_0206ea8c
extern "C" ARM int func_0206ea8c(unsigned char* base, unsigned char idx, int arg, int value) {
    struct Obj { unsigned char pad[0x41b]; unsigned char rows[2][0x20]; };
    short row;
    short half;
    unsigned short bit;
    struct Obj* s;
    int v;
    half = idx & 1;
    row = arg >> 3;
    bit = (arg & 7) ^ 7;
    s = (struct Obj*)base;
    if (value != 0) {
        v = 0;
        v = s->rows[half][row] | (1 << bit) - v;
        s->rows[half][row] = v;
    } else {
        v = s->rows[half][row];
        v &= ~(1 << bit);
        s->rows[half][row] = v;
    }
    return v;
}
