#include <globaldefs.h>

#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

#define F(x, y, z) (((x) & (y)) | (~(x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & ~(z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | ~(z)))

#define STEP(f, a, b, c, d, w, s) { unsigned long xv = (w); unsigned long sum = a + f(b, c, d) + xv + *t++; a = b + ROTATE_LEFT(sum, s); }

struct MD5Context020c04e8 {
    unsigned long a, b, c, d;
    unsigned long long length;
    union {
        unsigned long buffer32[16];
        unsigned char buffer8[64];
    };
};

extern unsigned long data_020f2050[64];
extern int data_020f1f90[48];

// USA: func_020c04e8
extern "C" ARM void func_020c04e8(MD5Context020c04e8* context) {
    const int* indices;
    unsigned long a;
    unsigned long b;
    unsigned long c;
    unsigned long d;
    unsigned long* x;
    const unsigned long* t;
    const unsigned long* words;
    int i;
    int j;
    int k;
    int l;

    a = context->a;
    b = context->b;
    c = context->c;
    d = context->d;
    x = context->buffer32;
    t = data_020f2050;

    words = x;
    i = 0;
    do {
        STEP(F, a, b, c, d, *words++, 7);
        STEP(F, d, a, b, c, *words++, 12);
        STEP(F, c, d, a, b, *words++, 17);
        STEP(F, b, c, d, a, *words++, 22);
        i++;
    } while (i < 4);

    indices = data_020f1f90;
    j = 0;
    do {
        STEP(G, a, b, c, d, x[*indices++], 5);
        STEP(G, d, a, b, c, x[*indices++], 9);
        STEP(G, c, d, a, b, x[*indices++], 14);
        STEP(G, b, c, d, a, x[*indices++], 20);
        j++;
    } while (j < 4);

    k = 0;
    do {
        STEP(H, a, b, c, d, x[*indices++], 4);
        STEP(H, d, a, b, c, x[*indices++], 11);
        STEP(H, c, d, a, b, x[*indices++], 16);
        STEP(H, b, c, d, a, x[*indices++], 23);
        k++;
    } while (k < 4);

    l = 0;
    do {
        STEP(I, a, b, c, d, x[*indices++], 6);
        STEP(I, d, a, b, c, x[*indices++], 10);
        STEP(I, c, d, a, b, x[*indices++], 15);
        STEP(I, b, c, d, a, x[*indices++], 21);
        l++;
    } while (l < 4);
    context->a += a;
    context->b += b;
    context->c += c;
    context->d += d;
}
