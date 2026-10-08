#include <globaldefs.h>

struct Vec3s32_020c3030 {
    int x;
    int y;
    int z;
};
extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

struct Bits40_37464 {
    char unk0[0x40];
    unsigned char lo3 : 3;
    unsigned char hi5 : 5;
};
extern "C" int _ZNK8Object3D17GetInheritedAlphaEv(struct Bits40_37464* obj);

extern "C" void func_02076a8c(unsigned char* p);
extern "C" void _ZN8Object3D10MakeHiddenEv(unsigned char* obj);

struct BitFlag02033f44 {
    char pad[0xe0];
    unsigned char bits0_5 : 6;
    unsigned char flag40 : 1;
    unsigned char bit7 : 1;
    char pad2[3];
    int field_e4;
};
int* GetField0xe4IfFlag0x40(struct BitFlag02033f44* p);

struct Struct020372b8 {
    char pad[0x40];
    unsigned char lo3 : 3;
    unsigned char field5 : 5;
    char pad2[0x2f];
    unsigned short f70;
};
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(struct Struct020372b8* obj, int a, int b);

extern "C" void* func_02057924(void);

struct InitStruct02078484Struct {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    short f12;
    short f14;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20; int f24; int f28; int f2c; int f30;
    int f34; int f38; int f3c; int f40;
    int f44; int f48; int f4c;
};
extern "C" void _Z18InitStruct02078484P24InitStruct02078484Struct(struct InitStruct02078484Struct* p);

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Vec3i_020374f0 { int x; int y; int z; };
extern "C" struct Vec3i_020374f0 _ZNK8Object3D8GetScaleEv(unsigned char* src);

extern "C" void _Z26FindNodeAndProcess02057fb4Pvii(void* list, int id, int a3);

struct Actor02078398 {
    char pad0[0x44];
    struct Vec3s32_020c3030 f44;
    char pad50[0x62];
    unsigned short fb2;
    char padb4[0xa4];
    struct Vec3s32_020c3030 f158;
    char pad164[0x14];
    short f178;
};

// USA: func_02078398
extern "C" ARM void func_02078398(struct Actor02078398* obj) {
    if (_ZNK8Object3D17GetInheritedAlphaEv((struct Bits40_37464*)obj) == 0) {
        func_02076a8c((unsigned char*)obj);
        _ZN8Object3D10MakeHiddenEv((unsigned char*)obj);
        return;
    }

    if (_ZNK8Object3D17GetInheritedAlphaEv((struct Bits40_37464*)obj) == 0x1f) {
        int* fp = GetField0xe4IfFlag0x40((struct BitFlag02033f44*)obj);
        struct Vec3s32_020c3030 v = obj->f44;
        v.y = 0;
        if (Vector3fix_Distance(&v, &obj->f158) < 0x2000 || fp != 0) {
            obj->fb2 = 0;
            _ZN8Object3D24TransitionInheritedAlphaEii((struct Struct020372b8*)obj, 0, 0x7d);
            if (obj->f178 > 0) {
                void* list = func_02057924();
                struct InitStruct02078484Struct s;
                _Z18InitStruct02078484P24InitStruct02078484Struct(&s);
                _ZN8Vector3iaSERKS_(&s.f2c, (int*)&obj->f44);
                const struct Vec3i_020374f0& tmp = _ZNK8Object3D8GetScaleEv((unsigned char*)obj);
                _ZN8Vector3iaSERKS_(&s.f44, (int*)&tmp);
                _Z26FindNodeAndProcess02057fb4Pvii(list, (int)obj->f178, (int)&s);
            }
        }
    }
}
