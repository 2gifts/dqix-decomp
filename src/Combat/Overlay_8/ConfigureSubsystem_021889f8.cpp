#include <globaldefs.h>
#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif


void SetBitfield0205af84(int a, void* b, int c);
extern "C" void func_0205ac40(int a, void* b);

struct Sub021889f8 { char pad[0x2bc]; int f2bc; int f2c0; };

struct Obj021889f8 {
    char pad0[0x730];
    int f730;
    struct Sub021889f8* f734;
    char pad1[0xb18 - 0x738];
    unsigned int flags_b18;
};

// USA: func_ov008_021889f8
ARM void ConfigureSubsystem_021889f8(struct Obj021889f8* obj) {
    if (obj->f730 == 0) return;
    if (!(obj->flags_b18 & 0x80000)) return;
    struct Sub021889f8* s = obj->f734;
    s->f2bc = R(0xd0000, 0xc8000);
    s->f2c0 = 0x62000;
    SetBitfield0205af84(obj->f730, (char*)obj->f734 + 0x2a8, 1);
    func_0205ac40(obj->f730, (char*)obj->f734 + 0x2a8);
}
