#include <globaldefs.h>

#if defined(jpn)
struct State0204166c {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
#if defined(jpn)
    int f14;
    unsigned char f18;
    unsigned char f19;
    unsigned char f1a;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char upperFlags : 5;
#else
    unsigned short f14;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char pad16 : 4;
    unsigned char f17;
    int f18;
#endif
};

// USA: func_020416c0
extern "C" ARM void func_02041bbc(struct State0204166c* s) {
    s->f0 = 0;
    s->f4 = 0;
    s->f8 = -1;
    s->fc = 0;
    s->f10 = 0;
    s->f14 = 0;
#if defined(jpn)
    s->f19 = 0;
    s->f18 = 0;
    s->f1a = 12;
    s->flag0 = 0;
    s->flag1 = 0;
    s->flag2 = 0;
#else
    s->f18 = 0;
    s->flag0 = 0;
    s->flag1 = 0;
    s->flag2 = 0;
    s->flag3 = 0;
    s->f17 = 0;
#endif
}
#else

struct State0204166c;
void ResetState0204166c(struct State0204166c* s);

// USA: func_020416c0
ARM void Forward020416c0(struct State0204166c* s) {
    ResetState0204166c(s);
}
#endif
