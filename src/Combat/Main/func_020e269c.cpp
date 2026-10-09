#include <globaldefs.h>

extern unsigned short data_02114e30;

struct RectList020e1eb0 {
    char pad0[8];
    unsigned char count;
};

extern "C" int _Z37FindRectIndexForCurrentCoords020e1e4cP16RectList020e1eb0(struct RectList020e1eb0* list);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" long long _s32_div_f(int a, int b);

struct Sel020e269c {
    char pad0[0x10];
    struct RectList020e1eb0* list;
    signed char cur;
    unsigned char prev;
    char pad1;
    unsigned char flag;
};

// USA: func_020e269c
extern "C" ARM void func_020e269c(struct Sel020e269c* self) {
    struct RectList020e1eb0* l = self->list;
    int step = l->count;
    int idx = _Z37FindRectIndexForCurrentCoords020e1e4cP16RectList020e1eb0(l);
    if (idx >= 0) {
        signed char cur = self->cur;
        if (cur == idx && self->flag) {
            self->prev = cur;
        }
        self->flag = 1;
        self->cur = idx;
        return;
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80)) {
        self->cur = (int)(_s32_div_f(self->cur + 1, step) >> 32);
        self->flag = 0;
        return;
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40)) {
        signed char v = self->cur;
        self->cur = (v > 0) ? v - 1 : step - 1;
        self->flag = 0;
        return;
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1) ||
        TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400) ||
        TestFlag0SetAndFlag1Clear(&data_02114e30, 0x200)) {
        self->prev = self->cur;
    }
}