#include <globaldefs.h>

#if defined(jpn)
#define data_020f1f14 data_020f2080
#endif

struct TableEntry020bb740 {
    int a;
    int b;
    char pad[0x10];
};

extern struct TableEntry020bb740 data_020f1f14[];

// USA: func_020bb740
ARM void RestorePairTableFromBuffer(int* out) {
    int i = 0;
    int j = 0;
    struct TableEntry020bb740* dst = data_020f1f14;
    do {
        dst->a = out[j];
        dst->b = (out + j)[1];
        j = j + 2;
        dst = dst + 1;
        i = i + 1;
    } while (i < 5);
}
