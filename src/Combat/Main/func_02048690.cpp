#include <globaldefs.h>

extern "C" void func_020489e8(void* obj);
extern "C" void _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(void* obj, int val);
extern "C" void* func_02057924(void);
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(void* obj, int a, int b);
extern "C" void _ZNK8Object3D20MaybeGetShadowSourceEv(int* out, void* obj);
extern "C" void _Z26FindNodeAndProcess02057fb4Pvii(void* list, int id, void* a3);

struct Obj0205eaa0;
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern unsigned char data_02108760;

struct Vec3i02048690 {
    int x;
    int y;
    int z;
};

struct InitStruct02048690 {
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

struct Self02048690 {
    char pad0[0xe0];
    unsigned char bitsE0 : 3;
    unsigned char flagE0 : 1;
    char pad1[0x183 - 0xe1];
    unsigned char countdown;
    char pad2[0x18e - 0x184];
};

// USA: func_02048690
extern "C" ARM void func_02048690(void* selfp) {
    struct Self02048690* self = (struct Self02048690*)selfp;

    func_020489e8(self);

    if (self->countdown != 0) {
        self->countdown--;
        if (self->countdown == 0) {
            _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(self, 5);
        }
    }

    if (self->flagE0 == 0) return;

    void* list = func_02057924();
    _ZN8Object3D24TransitionInheritedAlphaEii(self, 0, 0x1f4);

    int d = *(short*)((char*)self + 0x100 + 0x8e) - 0x1000;
    int f = (int)(((long long)d * 0x800 + 0x800) >> 12);
    f = f + 0x1000;
    f = (int)(((long long)f * 0x10a + 0x800) >> 12);

    struct InitStruct02048690 s;
    s.f00 = 0;
    s.f10 = 1;
    s.f12 = 0;
    s.f14 = -1;
    s.f16 = -1;
    s.f18 = -1;
    s.f1a = -1;
    s.f1c = -0x1000;
    s.f20 = 0;
    s.f24 = 0;
    s.f28 = 0;
    s.f2c = 0;
    s.f30 = 0;
    s.f34 = 0;
    s.f38 = 0;
    s.f3c = 0;
    s.f40 = 0;
    s.f44 = 0x1000;
    s.f48 = 0x1000;
    s.f4c = 0x1000;
    s.b0 = 0;
    s.b1 = 0;
    s.b2 = 1;
    s.b3 = 0;
    s.b4 = 0;
    s.b5 = 0;
    s.b6 = 0;
    s.b7 = 0;

    struct Vec3i02048690 p;
    _ZNK8Object3D20MaybeGetShadowSourceEv((int*)&p, self);
    s.f2c = p.x;
    s.f30 = p.y;
    s.f34 = p.z;
    s.f44 = f;
    s.f48 = f;
    s.f4c = f;

    _Z26FindNodeAndProcess02057fb4Pvii(list, 2, &s);
    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 0x32, 0);

    self->flagE0 = 0;
}