#include <globaldefs.h>

struct Obj02033874;
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void func_02048cf0(void* obj, int flag);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(struct Obj02033874* obj, int arg);

struct Triple02049d6c { unsigned int v[3]; };
extern "C" const struct Triple02049d6c data_020e7b18;

struct Sub02049d6c {
    unsigned int f0, f4, f8, fc;
    unsigned char pad10[0x10];
    unsigned int flags;
};

struct Obj02049d6c {
    unsigned char pad00[0x44];
    unsigned int vec44[3];
    unsigned char pad50[0xec];
    struct Sub02049d6c* sub;
};

// USA: func_02049d6c
extern "C" ARM void func_02049d6c(struct Obj02049d6c* self) {
    if (self->sub == NULL) return;
    func_02048cf0(self, 0);
    self->sub->flags &= ~0x21;
    struct Sub02049d6c* p = self->sub;
    p->flags |= 2;
    struct Triple02049d6c t = data_020e7b18;
    t.v[0] = self->sub->f4;
    t.v[2] = self->sub->fc;
    unsigned int y = self->sub->f8;
    _ZN8Vector3iaSERKS_((int*)self->vec44, (int*)&t);
    _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)self, y);
}
