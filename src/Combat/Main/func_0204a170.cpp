#include <globaldefs.h>
#include "System/Matrix.h"
#include "Graphics/Vector.h"
#include "GameState/GameState.h"

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" Vector3fix _ZNK8Object3D8GetScaleEv(void* src);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(void* dst, const Vector3fix& src);
extern "C" void _ZN8Object3D24MaybeUpdateBonePositionsEv(void* obj);
extern "C" void func_020a2d14(void* actor);
extern "C" void func_0204a4ac(void* self);
extern "C" void func_0202eab8(void* obj);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int angle);

struct S020a3570;
int GetField0x218(struct S020a3570* p);

struct Obj02033874;
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(struct Obj02033874* obj, int arg);

extern Matrix4x3 data_02107874;
extern Matrix4x3 data_021078ac;
extern Matrix4x3 data_021078e4;

struct Obj3D0204a170 {
    char pad0[0x44];
    Vector3fix pos;
    Vector3fix rot;
};

struct Obj0204a170 {
    char pad0[0x4];
    Vector3fix f04;
    Vector3fix f10;
    char pad1[0x21c - 0x1c];
    struct Obj3D0204a170* f21c;
    struct Obj3D0204a170* f220;
    char pad2[0x260 - 0x224];
    int f260;
    unsigned char f264;
    unsigned char f265;
};

// USA: func_0204a170
extern "C" ARM void func_0204a170(struct Obj0204a170* self) {
    Matrix4x3 m1;
    Matrix4x3 m2;
    Matrix4x3 m3;


    if (self->f21c == NULL) return;

    if (self->f260 >= 0) {
        GameState* bs = GameState::GetInstance();
        void* target = bs->GetGameObjectByIndex(self->f260);
        if (target != NULL) {
            _ZN8Vector3iaSERKS_((int*)&self->f21c->pos, (int*)((char*)target + 0x44));
            _ZN8Vector3iaSERKS_((int*)&self->f21c->rot, (int*)((char*)target + 0x50));
            _ZN8Object3D8SetScaleEPK8Vector3i(self->f21c, _ZNK8Object3D8GetScaleEv(target));
        }
    }

    func_020a2d14(self);
    if (GetField0x218((struct S020a3570*)self) != 0) return;
    func_0204a4ac(self);

    const Vector3fix& scale = _ZNK8Object3D8GetScaleEv(self->f21c);
    _ZN8Object3D24MaybeUpdateBonePositionsEv(self->f21c);

    m1 = data_02107874;
    m2 = data_021078ac;
    m3 = data_021078e4;

    Vector3fix v1;
    Vector3fix v2;
    Vector3fix v3;

    v1.x = m1.translation.x; v1.y = m1.translation.y; v1.z = m1.translation.z;
    v2.x = m2.translation.x; v2.y = m2.translation.y; v2.z = m2.translation.z;
    v3.x = m3.translation.x; v3.y = m3.translation.y; v3.z = m3.translation.z;

    Vector3fixMultiply(&v1, &scale, &v1);
    Vector3fixMultiply(&v2, &scale, &v2);
    Vector3fixMultiply(&v3, &scale, &v3);

    Obj3D0204a170* o = self->f21c;
    Vector3fix_Add(&v1, &o->pos, &v1);
    Vector3fix_Add(&v2, &o->pos, &v2);
    Vector3fix_Add(&v3, &o->pos, &v3);

    _ZN8Vector3iaSERKS_((int*)&self->f10, (int*)&v2);
    _ZN8Vector3iaSERKS_((int*)&self->f04, (int*)&v1);
    func_0202eab8(self);

struct Obj3D0204a170* t = self->f220;
    if (t == NULL) return;

    int angle = _Z22fix32ReduceAngle0To2Pii(fix32_Atan2(v3.x - t->pos.x,
                                                        v3.z - t->pos.z));
    struct Obj3D0204a170* u = self->f220;
    _ZN8Vector3iaSERKS_((int*)&u->pos, (int*)&v3);

    if (self->f265 != 0) return;

    self->f264++;
    if (self->f264 >= 3) {
        _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)u,
            FIX32_MULTIPLY(t->rot.y + angle, 0x800));
        self->f264 = 0;
    } else {
        _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)u, t->rot.y);
    }
}