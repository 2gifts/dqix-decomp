#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" void* func_0202ae18(void);
extern "C" void* func_02057924(void);
extern "C" void __clear(void* buf, int n);

struct Struct020372b8;

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
void InitStruct02078484(struct InitStruct02078484Struct* p);

struct Vector3i;

struct Vec3i_020374f0 { int x; int y; int z; };
extern "C" struct Vec3i_020374f0 _ZNK8Object3D8GetScaleEv(unsigned char* src);

void FindNodeAndProcess02057fb4(void* list, int id, int a3);

int CheckField0NonZero_0202b7d8(int* obj);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct U16Field0x6_020375f8;

struct Vec3Zero0207853c { int a; int b; int c; };
extern "C" void func_ov017_021c95ec(int c1, int rem, int f2val, int tag, int negOne, struct Vec3Zero0207853c v, int a8, int a9, int a10);

struct Entity0207853c {
    char pad0[0x2];
    short f2;
    short f4;
    unsigned short f6;
    char pad1[0x3c];
    int f44; int f48; int f4c;
    char pad2[0x62];
    short fb2;
    char pad3[0xc4];
    short f178;
};

// USA: func_0207853c  (semantic: ProcessEntityFieldsAndQueueEvent_0207853c)
extern "C" ARM int func_0207853c(struct Entity0207853c* obj) {
    void* g = func_0202ae18();
    obj->fb2 = 0;
    ((Object3D*)((struct Struct020372b8*)obj))->TransitionInheritedAlpha(0, 0x7d);

    if (obj->f178 > 0) {
        void* list = func_02057924();
        struct InitStruct02078484Struct s;
        InitStruct02078484(&s);
        *(Vector3i*)&s.f2c = *(Vector3i const*)&obj->f44;
        const struct Vec3i_020374f0& tmp = _ZNK8Object3D8GetScaleEv((unsigned char*)obj);
        *(Vector3i*)&s.f44 = *(Vector3i const*)((int*)&tmp);
        FindNodeAndProcess02057fb4(list, obj->f178, (int)&s);
    }

    if (CheckField0NonZero_0202b7d8((int*)g) && GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g) == 0) {
        int c1 = ((Object3D*)((struct U16Field0x6_020375f8*)obj))->GetField06();
        int f2val = obj->f2;
        int rem = (obj->f4 - 0x70) % 0xc;
        if (rem >= 0 && rem < 0xc) {
            struct Vec3Zero0207853c v;
            __clear(&v, 0xc);
            func_ov017_021c95ec(c1, rem, f2val, 0xb, -1, v, 0, 0, 0);
        }
    }

    return 1;
}
