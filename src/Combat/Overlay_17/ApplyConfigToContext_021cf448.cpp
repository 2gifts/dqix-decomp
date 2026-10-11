#include <globaldefs.h>

extern "C" void func_ov017_021bff8c(int a, int b);

struct Src021cf448 {
    char pad0[4];
    int f4;
    int f8;
    int fc;
    unsigned short f10;
    struct {
        unsigned char flagA : 1;
        unsigned char flagB : 1;
    } bits;
    signed char f13;
};

// JPN: func_ov017_021cf8f8
// USA: func_ov017_021cf448
ARM void ApplyConfigToContext_021cf448(int unused, Src021cf448* src, unsigned char* base, int extra) {
#if defined(jpn)
 enum {regionalOffset0=0x7ca8, regionalOffset1=0x7cac, regionalOffset2=0x7cb0, regionalOffset3=0x7cb4, regionalOffset4=0x7ca0, regionalOffset5=0x7ca1};
#else
 enum {regionalOffset0=0x7f7c, regionalOffset1=0x7f80, regionalOffset2=0x7f84, regionalOffset3=0x7f88, regionalOffset4=0x7f74, regionalOffset5=0x7f75};
#endif
    *(int*)(base + regionalOffset0) = src->f4;
    *(int*)(base + regionalOffset1) = src->f8;
    *(int*)(base + regionalOffset2) = src->fc;
    *(unsigned short*)(base + regionalOffset3) = src->f10;
    base[regionalOffset4] = src->bits.flagA;
    base[regionalOffset5] = src->bits.flagB;
    if (base[regionalOffset4] != 0) {
        func_ov017_021bff8c(extra, src->f13);
    }
}
