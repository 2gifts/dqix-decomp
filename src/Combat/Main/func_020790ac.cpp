#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
extern "C" void __clear(void* buf, int n);

int CheckField0NonZero(int* obj);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

struct Object3D;
extern "C" int func_02079238(Object3D* obj, int arg);
extern "C" short func_020793c0(Object3D* obj, int maximumDistance);
extern "C" int _Z18TrySetMode02076cccPvi(void* obj, int mode);

struct Vec3Zero020790ac { int a; int b; int c; };
extern "C" void func_ov017_021c95ec(int c1, int rem, int f2val, int tag, int phase,
                                    struct Vec3Zero020790ac v, int a8, int a9, int a10);

struct Obj020790ac {
    char pad0[2];
    short f2;
    short f4;
    char pad6[0x130 - 6];
    int f130;
    char pad134[0x13a - 0x134];
    unsigned char f13a;
    char pad13b[0x154 - 0x13b];
    unsigned int f154;
    char pad158[0x166 - 0x158];
    short f166;
    char pad168[0x17b - 0x168];
    unsigned char f17b;
};

// USA: func_020790ac
extern "C" ARM void func_020790ac(struct Obj020790ac* obj) {
    if (obj->f130 != 1 && obj->f130 != 2) return;

    void* g = func_0202ae18();
    if (CheckField0NonZero((int*)g) && GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g) != 0) {
        return;
    }
    if (obj->f154 < 0x7d0) return;
    if (obj->f17b != 0) return;

    int phase = -1;
    switch (obj->f13a) {
    case 1: phase = func_02079238((Object3D*)obj, 0x3800); break;
    case 2: phase = func_02079238((Object3D*)obj, 0x7800); break;
    case 3: phase = func_020793c0((Object3D*)obj, 0x3800); break;
    case 4: phase = func_020793c0((Object3D*)obj, 0x7800); break;
    default: break;
    }
    if (phase == -1) return;

    obj->f166 = phase;
    _Z18TrySetMode02076cccPvi(obj, 0xa);

    void* g2 = func_0202ae18();
    if (!CheckField0NonZero((int*)g2) || GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g2) != 0) {
        return;
    }

    int id = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)obj);
    int f2val = obj->f2;
    int rem = (obj->f4 - 0x70) % 0xc;
    if (rem >= 0 && rem < 0xc) {
        struct Vec3Zero020790ac v;
        __clear(&v, 0xc);
        func_ov017_021c95ec(id, rem, f2val, 0xa, phase, v, 0, 0, 0);
    }
}
