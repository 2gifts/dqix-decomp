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
int* GetField0xe4IfFlag0x40(struct BitFlag02033f44* self);

void TrySetMode02076ccc(void* self, int mode);

int CheckField0NonZero_0202b7d8(int*);

extern "C" void func_020794f8(void* self, int a, int b);

struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

extern "C" int func_0202c540(void* obj);

extern "C" void* func_02012fe4(void);

struct U16Field0x6_020375f8;

extern "C" int func_02018fbc(int seed, void* v);

struct Vector3i;

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

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
extern "C" ARM void func_02078050(struct Entity02078050* self) {
    void* mgr = func_0202ae18(self);

    if (GetField0xe4IfFlag0x40((struct BitFlag02033f44*)self) != 0) {
        TrySetMode02076ccc(self, 1);
        self->f154 = 0;
        if (CheckField0NonZero_0202b7d8((int*)mgr) == 0) {
            return;
        }
        func_020794f8(self, 0, 0);
        return;
    }

    self->fb4 = 0x1c2;
    self->fb2 = 0x1c2;
    SetByteIfChanged02033b68((struct Obj02033b68*)self, 1);

    struct Vec3 pos44 = self->f44;
    pos44.y = 0;
    struct Vec3 pos158 = self->f158;
    pos158.y = 0;
    struct Vec3 delta;
    int dist;

    dist = Vector3fix_Distance((const Vector3fix*)&pos44, (const Vector3fix*)&pos158);
    Vector3fix_Subtract((const Vector3fix*)&pos158, (const Vector3fix*)&pos44, (Vector3fix*)&delta);
    Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
    SetVecYByMode02033834((struct Obj02033834*)self, fix32_Atan2(delta.x, delta.z));

    if (func_0202c540(mgr) != 0) {
        return;
    }

    if (dist >= 0x1800) {
        return;
    }

    struct Flags02078050* flags = (struct Flags02078050*)func_02012fe4();
    struct Vec3 v = self->f44;
    unsigned short curId = flags->f00;

    if (curId == ((Object3D*)((struct U16Field0x6_020375f8*)self))->GetField06() && flags->f424 == 0) {
        v.y = func_02018fbc((int)flags, &v);
        *(Vector3i*)((int*)&self->f44) = *(Vector3i const*)((int*)&v);
    }

    TrySetMode02076ccc(self, 1);
    self->f154 = 0;
    if (CheckField0NonZero_0202b7d8((int*)mgr) == 0) {
        return;
    }
    if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)mgr) != 0) {
        return;
    }
    func_020794f8(self, 0, 0);
}
