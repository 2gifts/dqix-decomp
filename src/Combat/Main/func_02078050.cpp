#if defined(jpn)
enum { RegionalPad = 0x442 };
#else
enum { RegionalPad = 0x422 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };

extern "C" void* func_0202ae18(void* self);

struct BitFlag02033f44;
extern "C" int* _Z22GetField0xe4IfFlag0x40P15BitFlag02033f44(struct BitFlag02033f44* self);

extern "C" void _Z18TrySetMode02076cccPvi(void* self, int mode);

extern "C" int _Z18CheckField0NonZeroPi(void* obj);

extern "C" void func_020794f8(void* self, int a, int b);

struct Obj02033b68;
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(struct Obj02033b68* obj, int newVal);

struct Obj02033834;
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(struct Obj02033834* obj, int arg);

extern "C" int func_0202c540(void* obj);

extern "C" void* func_02012fe4(void);

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

extern "C" int func_02018fbc(int seed, void* v);

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct SearchStruct0202c1a4;
extern "C" signed char _Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4(struct SearchStruct0202c1a4* obj);

struct Flags02078050 {
    unsigned short f00;
    unsigned char pad02[RegionalPad];
    int f424;
};

struct Entity02078050 {
    char pad0[0x44];
    struct Vec3 f44;
    char pad50[0x62];
    unsigned short fb2;
    unsigned short fb4;
    char padb6[0x9e];
    int f154;
    struct Vec3 f158;
};

// USA: func_02078050
// JPN: func_02078050
extern "C" ARM void func_02078050(struct Entity02078050* self) {
    void* mgr = func_0202ae18(self);

    if (_Z22GetField0xe4IfFlag0x40P15BitFlag02033f44((struct BitFlag02033f44*)self) != 0) {
        _Z18TrySetMode02076cccPvi(self, 1);
        self->f154 = 0;
        if (_Z18CheckField0NonZeroPi(mgr) == 0) {
            return;
        }
        func_020794f8(self, 0, 0);
        return;
    }

    self->fb4 = 0x1c2;
    self->fb2 = 0x1c2;
    _Z24SetByteIfChanged02033b68P11Obj02033b68i((struct Obj02033b68*)self, 1);

    struct Vec3 pos44 = self->f44;
    pos44.y = 0;
    struct Vec3 pos158 = self->f158;
    pos158.y = 0;
    struct Vec3 delta;
    int dist;

    dist = Vector3fix_Distance((const Vector3fix*)&pos44, (const Vector3fix*)&pos158);
    Vector3fix_Subtract((const Vector3fix*)&pos158, (const Vector3fix*)&pos44, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    _Z21SetVecYByMode02033834P11Obj02033834i((struct Obj02033834*)self, fix32_Atan2(delta.x, delta.z));

    if (func_0202c540(mgr) != 0) {
        return;
    }

    if (dist >= 0x1800) {
        return;
    }

    struct Flags02078050* flags = (struct Flags02078050*)func_02012fe4();
    struct Vec3 v = self->f44;
    unsigned short curId = flags->f00;

    if (curId == _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)self) && flags->f424 == 0) {
        v.y = func_02018fbc((int)flags, &v);
        _ZN8Vector3iaSERKS_((int*)&self->f44, (int*)&v);
    }

    _Z18TrySetMode02076cccPvi(self, 1);
    self->f154 = 0;
    if (_Z18CheckField0NonZeroPi(mgr) == 0) {
        return;
    }
    if (_Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4((struct SearchStruct0202c1a4*)mgr) != 0) {
        return;
    }
    func_020794f8(self, 0, 0);
}
