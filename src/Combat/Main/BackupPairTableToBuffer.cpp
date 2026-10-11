#include <globaldefs.h>

#if defined(jpn)
#define data_020f1f14 data_020f2080
#endif

struct TableEntry020bb700 {
    int a;
    int b;
    char pad[0x10];
};

extern struct TableEntry020bb700 data_020f1f14[];

// USA: func_020bb700
ARM void BackupPairTableToBuffer(int* out) {
    int i = 0;
    struct TableEntry020bb700* src = data_020f1f14;
    int j = 0;
    do {
        out[j] = src->a;
        (out + j)[1] = src->b;
        src = src + 1;
        j = j + 2;
        i = i + 1;
    } while (i < 5);
}
