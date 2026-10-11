#include <globaldefs.h>

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Obj02033874;
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(struct Obj02033874* obj, int arg);

struct Triple02049e00 { unsigned int v[3]; };
extern "C" const struct Triple02049e00 data_020e7b24;

struct Sub02049e00 {
    unsigned char pad[0x10];
    unsigned int f10, f14, f18;
    unsigned char pad1c[4];
    unsigned int flags;
};

struct Obj02049e00 {
    unsigned char pad[0x44];
    unsigned int vec44[3];
    unsigned char pad50[0xec];
    struct Sub02049e00* sub;
};

// USA: func_02049e00
extern "C" ARM void func_02049e00(struct Obj02049e00* self) {
    if (self->sub == NULL) return;
    self->sub->flags &= ~0x22;
    Sub02049e00* p = self->sub;
    p->flags |= 1;
    struct Triple02049e00 t = data_020e7b24;
    t.v[0] = self->sub->f10;
    t.v[2] = self->sub->f18;
    unsigned int y = self->sub->f14;
    _ZN8Vector3iaSERKS_((int*)self->vec44, (int*)&t);
    _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)self, y);
}
