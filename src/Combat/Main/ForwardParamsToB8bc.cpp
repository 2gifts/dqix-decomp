#include <globaldefs.h>

extern char data_02105254;

struct Bcb8Params {
    unsigned char b0;
    unsigned char b1;
    unsigned char pad2[6];
    unsigned int w8;
    unsigned char padC[8];
    unsigned short h14;
    unsigned short h16;
    unsigned short h18;
};

extern "C" void func_0203b8bc(void* a0, int a1, int a2, int a3, int a4,
                              unsigned int a5, int a6, int a7, int a8);

// USA: func_0203bcb8
ARM void ForwardParamsToB8bc_0203bcb8(struct Bcb8Params* s, int arg1, int arg2) {
    func_0203b8bc(&data_02105254, s->h16, s->h18, arg1, arg2,
                  s->w8, s->b0, s->b1, s->h14);
}
