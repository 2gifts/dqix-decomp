#include <globaldefs.h>
#include "World/Object3D.h"
#include "Graphics/Vector.h"

struct ViewObject
{
    char unk_0[0x1c];
    unsigned char kind_;
    char unk_1d[3];
    int* parts_;
    Object3D* objects_;
};

static inline const Vector3fix& GetRotation(const Object3D* o)
{
    return o->rotation_;
}

static inline void SetRotation(Object3D* o, const Vector3fix& rotation)
{
    o->rotation_ = rotation;
}

// USA: func_ov015_0218f5f8
extern "C" ARM void func_ov015_0218f5f8(ViewObject* self, int angle)
{
    Vector3fix rotation = {0};
    switch (self->kind_)
    {
    case 0:
        rotation = GetRotation(&self->objects_[1]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        SetRotation(&self->objects_[1], rotation);
        rotation = GetRotation(&self->objects_[0]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        SetRotation(&self->objects_[0], rotation);
        break;
    case 1:
        rotation = GetRotation(&self->objects_[6]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        SetRotation(&self->objects_[6], rotation);
        rotation = GetRotation(&self->objects_[1]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        SetRotation(&self->objects_[1], rotation);
        rotation = GetRotation(&self->objects_[5]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        SetRotation(&self->objects_[5], rotation);
        rotation = GetRotation(&self->objects_[0]);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        SetRotation(&self->objects_[0], rotation);
        break;
    default:
        rotation = GetRotation(self->objects_);
        rotation.y = fix32ReduceAngle0To2Pi(rotation.y + angle);
        SetRotation(self->objects_, rotation);
        break;
    }
}
