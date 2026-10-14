#include <globaldefs.h>

struct InitStruct {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    unsigned char b24;
    unsigned char b25;
    int w28;
};

// USA: func_020280b0
ARM void InitializeStruct_020280b0(struct InitStruct* s) {
    s->w1c = 0;
    s->b0 = 0;
    s->b1 = 0;
    s->b2 = 0;
    s->b3 = 0;
    s->w4 = 0;
    s->w8 = 0;
    s->wc = 0;
    s->w10 = 0;
    s->w14 = 0;
    s->w18 = 0;
    s->w20 = 1;
    s->b24 = 0;
    s->b25 = 0;
    s->w28 = 0;
}
