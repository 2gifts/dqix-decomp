#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_0216c28c(void *base, int ev);

struct Ent6_0216c2d8 {
    unsigned char b0;
    char pad1;
    short s2;
    unsigned char b4;
    char pad5;
};

struct Hi0216c2d8 {
    char pad0[0xccb];
    unsigned char count;
};

// USA: func_ov002_0216c2d8
extern "C" ARM void func_ov002_0216c2d8(char *base, signed char *keys, struct Ent6_0216c2d8 *srcA, struct Ent6_0216c2d8 *srcB,
                                        int n) {
    struct Ent6_0216c2d8 *a = (struct Ent6_0216c2d8 *) (base + 0x1cd0);
    struct Ent6_0216c2d8 *b = (struct Ent6_0216c2d8 *) (base + 0x1ce8);
    int i;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < ((struct Hi0216c2d8 *) (base + 0x1000))->count; j++) {
            if (*(signed char *) (base + j + 0x1ccc) == keys[i]) {
                a[j].s2 = srcA[i].s2;
                a[j].b0 = srcA[i].b0;
                a[j].b4 = 0;
                b[j].s2 = srcB[i].s2;
                b[j].b0 = srcB[i].b0;
                b[j].b4 = 0;
            }
        }
    }

    int sum = 0;
    for (i = 0; i < ((struct Hi0216c2d8 *) (base + 0x1000))->count; i++) {
        sum += a[i].b4;
    }
    if (sum == 0) {
        func_ov002_0216c28c(base, 0x15);
    }
    if (a[0].b0 != 3) {
        *(unsigned char *) (base + 0x2522) = 0;
        *(unsigned char *) (base + 0x2523) = 0;
        memset(base + 0x2524, 0, 0xc);
        *(int *) (base + 0x2530) = 0;
    }
}
