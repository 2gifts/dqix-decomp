#include <globaldefs.h>

extern char data_021015a0;

// USA: func_0202d8e8
extern "C" ARM int func_0202d8e8(void) {
    signed short pos;
    unsigned short mask;
    unsigned short count;
    signed short i;
    unsigned short n;
    int seed;

    *(int*)(&data_021015a0 + 0x10) = 1;
    pos = 0;
    count = 0;
    i = 0;
    mask = *(unsigned short*)(&data_021015a0 + 0xc);

    for (i = 0; i < 0x10; i++) {
        if (mask & (1 << i)) {
            pos = i + 1;
            count = count + 1;
        }
    }

    if (count <= 1) {
        goto out;
    }

    seed = *(int*)(&data_021015a0 + 0x20);
    seed = seed * 0x10DCD + 0x3039;
    n = (unsigned short)((count * (seed & 0xff)) >> 8);
    *(int*)(&data_021015a0 + 0x20) = seed;

    for (i = 0; i < 0x10; i++) {
        if (mask & 1) {
            if (n == 0) {
                pos = i + 1;
                goto out;
            }
            n = n - 1;
        }
        mask >>= 1;
    }

    pos = 0;

out:
    return (*(unsigned short*)(&data_021015a0 + 2) = pos);
}