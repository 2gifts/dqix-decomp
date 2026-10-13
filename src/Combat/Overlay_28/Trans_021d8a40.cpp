#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Trans_021d8a40 {
    char pad0[0x8];
    unsigned int f8;
    char padc[0xa0 - 0xc];
    unsigned int fa0;
    char pada4[0xa8 - 0xa4];
    unsigned short fa8;
    unsigned short faa;
    unsigned short fac;
    unsigned short fae;
};

extern "C" void func_0204c684(void* obj);

// USA: func_ov028_021d8a40  (semantic: Trans_021d8a40)
extern "C" ARM void func_ov028_021d8a40(Trans_021d8a40* self, unsigned int val) {
    func_0204c684(self);
    self->f8 = val;
    self->fac = 0;
    self->fae = 0;
    self->fa8 = 0x20;
    self->faa = 0x20;
    self->fa0 = 0;
}
