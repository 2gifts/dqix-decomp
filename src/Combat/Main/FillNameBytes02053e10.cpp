#include <globaldefs.h>

#if defined(jpn)
enum { kFlagsOffset = 0x194 };
#else
enum { kFlagsOffset = 0x1a0 };
#endif


struct Struct0207ea38;
extern "C" int _ZN7Model3D12GetBoneIndexEPKc(struct Struct0207ea38* obj, char* str);

extern char data_020f048a;
extern char data_020f048f;
extern char data_020f0495;
extern char data_020f049b;
extern char data_020f04a1;
extern char data_020f04a7;
extern char data_020f04ad;

struct Obj02053e10 {
    char pad0[0x8];
    struct Struct0207ea38* field8;   // 0x8
    char pad1[kFlagsOffset - 0xc];
    unsigned char f1a0;
    unsigned char f1a1;
    unsigned char f1a2;
    unsigned char f1a3;
    unsigned char f1a4;
    unsigned char f1a5;
    unsigned char f1a6;
};

// USA: func_02053e10
ARM void FillNameBytes02053e10(struct Obj02053e10* self) {
    struct Struct0207ea38* obj = self->field8;
    if (obj == NULL)
        return;
    self->f1a0 = (unsigned char)_ZN7Model3D12GetBoneIndexEPKc(obj, &data_020f048a);
    self->f1a1 = (unsigned char)_ZN7Model3D12GetBoneIndexEPKc(obj, &data_020f048f);
    self->f1a2 = (unsigned char)_ZN7Model3D12GetBoneIndexEPKc(obj, &data_020f0495);
    self->f1a3 = (unsigned char)_ZN7Model3D12GetBoneIndexEPKc(obj, &data_020f049b);
    self->f1a4 = (unsigned char)_ZN7Model3D12GetBoneIndexEPKc(obj, &data_020f04a1);
    self->f1a5 = (unsigned char)_ZN7Model3D12GetBoneIndexEPKc(obj, &data_020f04a7);
    self->f1a6 = (unsigned char)_ZN7Model3D12GetBoneIndexEPKc(obj, &data_020f04ad);
}
