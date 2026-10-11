#include "std_library_functions.h"
#include <globaldefs.h>
#if defined(jpn)
#define func_ov002_0216c28c func_ov002_0216c8dc
#define ARRAY_A_OFFSET 0x1b94
#define ARRAY_B_OFFSET 0x1bac
#define COUNT_IN_HIGH 0xb8f
#define KEYS_OFFSET 0x1b90
#define FLAGS_OFFSET 0x2352
#else
#define ARRAY_A_OFFSET 0x1cd0
#define ARRAY_B_OFFSET 0x1ce8
#define COUNT_IN_HIGH 0xccb
#define KEYS_OFFSET 0x1ccc
#define FLAGS_OFFSET 0x2522
#endif

extern "C" void func_ov002_0216c28c(void *base, int ev);

struct Ent6_0216c2d8 {
    unsigned char b0;
    char pad1;
    short s2;
    unsigned char b4;
    char pad5;
};

struct Hi0216c2d8 {
    char pad0[COUNT_IN_HIGH];
    unsigned char count;
};

// USA: func_ov002_0216c2d8
extern "C" ARM void func_ov002_0216c2d8(char *base, signed char *keys, struct Ent6_0216c2d8 *srcA, struct Ent6_0216c2d8 *srcB,
                                        int n) {
    struct Ent6_0216c2d8 *a = (struct Ent6_0216c2d8 *) (base + ARRAY_A_OFFSET);
    struct Ent6_0216c2d8 *b = (struct Ent6_0216c2d8 *) (base + ARRAY_B_OFFSET);
    int i;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < ((struct Hi0216c2d8 *) (base + 0x1000))->count; j++) {
            if (*(signed char *) (base + j + KEYS_OFFSET) == keys[i]) {
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
        *(unsigned char *) (base + FLAGS_OFFSET) = 0;
        *(unsigned char *) (base + FLAGS_OFFSET + 1) = 0;
        memset(base + FLAGS_OFFSET + 2, 0, 0xc);
        *(int *) (base + FLAGS_OFFSET + 14) = 0;
    }
}
