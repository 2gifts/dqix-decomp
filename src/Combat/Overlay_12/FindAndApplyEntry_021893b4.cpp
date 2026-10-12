#if defined(jpn)
#define func_ov012_021893b4 func_ov012_02189c90
#endif

#include <globaldefs.h>

#if defined(jpn)
#define data_ov012_0218b008 data_ov012_0218bd28
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct Entry021893b4 {
    unsigned char key;
    unsigned char v1;
    unsigned char v2;
    signed char v3;
    signed char v4;
    unsigned char v5;
    unsigned char v6;
};
extern struct Entry021893b4 data_ov012_0218b008[];

struct Dest021893b4 {
    char pad[LOW_REGION(0x130, 0xa0)];
    short f_a0;
    short f_a2;
    short f_a4;
    short f_a6;
    short f_a8;
    short f_aa;
    short f_ac;
    short f_ae;
    char pad_b0;
    unsigned char f_b1;
    char pad_b2[3];
    unsigned char f_b5;
};

// USA: func_ov012_021893b4  (semantic: FindAndApplyEntry_021893b4)
extern "C" ARM void func_ov012_021893b4(void* obj, int key, int p2, int p3) {
    struct Dest021893b4* d = (struct Dest021893b4*)((char*)obj + LOW_REGION(0, 0xac));
    int i;
    for (i = 0; data_ov012_0218b008[i].key != 0xff; i++) {
        struct Entry021893b4* e = &data_ov012_0218b008[i];
        if (e->key == key) {
            unsigned char t2, t1v;
            signed char t4, t3v;
            unsigned char t6, t5v;
            d->f_b1 = e->key;
            d->f_a4 = p2;
            d->f_a6 = p3;
            t2 = e->v2;
            t1v = e->v1;
            d->f_a8 = t1v;
            d->f_aa = t2;
            t4 = e->v4;
            t3v = e->v3;
            d->f_a0 = t3v;
            d->f_a2 = t4;
            t6 = e->v6;
            t5v = e->v5;
            d->f_ac = t5v;
            d->f_ae = t6;
            d->f_b5 = 1;
            return;
        }
    }
}
