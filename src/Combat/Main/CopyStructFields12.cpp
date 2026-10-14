#include <globaldefs.h>

struct Record12 {
    unsigned short f0;
    unsigned short f2;
    int f4;
    unsigned short f8;
    unsigned short fa;
};

// USA: func_0209a530
ARM void CopyStructFields12_0209a530(struct Record12* dst, struct Record12* src) {
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f4 = src->f4;
    dst->f8 = src->f8;
    dst->fa = src->fa;
}
