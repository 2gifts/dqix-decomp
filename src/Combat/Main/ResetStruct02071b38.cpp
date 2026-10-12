#include <globaldefs.h>

struct FieldC02071b38 {
    unsigned int lo10 : 10;
    unsigned int mid10 : 10;
    unsigned int hi8 : 8;
    unsigned int top4 : 4;
};

struct Field1002071b38 {
    unsigned int lo10 : 10;
    unsigned int mid10 : 10;
    unsigned int bit20 : 1;
    unsigned int bit21 : 1;
    unsigned int bit22 : 1;
    unsigned int hi8 : 8;
    unsigned int bit31 : 1;
};

struct Struct02071b38 {
    short f0;
    short f2;
    short f4;
    short f6;
    short f8;
    unsigned short fa;
    FieldC02071b38 fc;
    Field1002071b38 f10;
    short f14;
    short f16;
    short f18;
    short f1a;
    int f1c;
};

// USA: func_02071b38  (semantic: ResetStruct02071b38)
extern "C" ARM void func_02071b38(Struct02071b38* s) {
    s->f0 = -1;
    s->f2 = -1;
    s->f4 = -1;
    s->f6 = -1;
    s->f8 = -1;
    unsigned short* pa = &s->fa;
    *pa &= ~0xf;
    *pa &= ~0xf0;
    *pa &= ~0xf00;
    *pa = (*pa & ~0xf000) | 0x1000;
    s->fc.lo10 = 0;
    s->fc.mid10 = 0;
    s->fc.hi8 = 0;
    s->f10.lo10 = 0;
    s->f10.mid10 = 0;
    s->f10.bit20 = 1;
    s->f10.bit21 = 0;
    s->f10.bit22 = 0;
    s->f10.hi8 = 0;
    s->f14 = -1;
    s->f16 = -1;
    s->f18 = -1;
    s->f1a = -1;
    s->f1c = 0;
}
