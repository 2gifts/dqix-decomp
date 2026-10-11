#include <globaldefs.h>
#if defined(jpn)
enum { kCountOffset = 0x497 };
#else
enum { kCountOffset = 0x477 };
#endif


struct Entry020159c0 {
    unsigned char pad0[0x14];
    signed char f14;
    unsigned char pad15[0xb];
    int f20;
};

struct Holder020159c0 {
    unsigned char pad0[kCountOffset];
    unsigned char count;
    unsigned char pad478[4];
    struct Entry020159c0* arr;
    unsigned char pad480[0x820 - 0x480];
    int f820;
};

// USA: func_020159c0
ARM void ClearMatchingEntries020159c0(struct Holder020159c0* holder, int key) {
    int valid;
    int i;
    if (key >= 0 && key <= 3) {
        valid = 1;
    } else {
        valid = 0;
    }
    if (valid == 0) {
        return;
    }
    for (i = 0; i < holder->count; i++) {
        struct Entry020159c0* e = &holder->arr[i];
        if (e->f20 != 0 && e->f14 == key) {
            e->f20 = 0;
            holder->f820 = 0;
        }
    }
}
