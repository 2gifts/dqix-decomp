#include <globaldefs.h>
#include "World/Object3D.h"

struct Obj02048cf0;

struct Vec2_0216f74c { int x; int y; };
struct Vec3_02048cf0 { int v[3]; };

struct Inner02048cf0 {
    char pad00[0x20];
    unsigned int flags20;
};

struct Obj02048cf0 {
    char pad00[0x44];
    int vec44[3];
    char pad50[0x6e];
    unsigned char b_be;
    char padbf[0x7d];
    Inner02048cf0* ptr;
};

int GetSubstructByte0x1e(unsigned char*);
int GetSubstructByte0x1d(unsigned char*);
int GetSubstructByte0x1c(unsigned char*);
void SetSubstructByte0x1c(unsigned char*, unsigned char);
void SetSubstructByte0x1d(unsigned char*, unsigned char);
void SetSubstructByte0x1e(unsigned char*, unsigned char);
void SetSubstructFields0x10And0x18ClearFlag0x1(unsigned char*, int*);
struct Bytes02033b88;
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
struct Obj02048c90;
void ResetInnerState02048c90(Obj02048c90*);
extern "C" struct Vec2_0216f74c func_ov000_0216f74c(int* in);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

extern Vec3_02048cf0 data_020e7b48;

// USA: func_02048cf0
extern "C" ARM void func_02048cf0(struct Obj02048cf0* obj, int flag) {
    int cell = GetSubstructByte0x1e((unsigned char*)obj);
    if (cell == 0xff) {
        cell = GetSubstructByte0x1d((unsigned char*)obj);
    }
    if (cell == 0xff) {
        cell = GetSubstructByte0x1c((unsigned char*)obj);
    }
    if (flag != 0) {
        cell = GetSubstructByte0x1c((unsigned char*)obj);
    }
    if (cell != 0xff) {
        struct Vec2_0216f74c pos = func_ov000_0216f74c(&cell);
        struct Vec3_02048cf0 fields = data_020e7b48;
        fields.v[0] = pos.x;
        fields.v[2] = pos.y;
        unsigned int flags20 = obj->ptr->flags20;
        SetSubstructFields0x10And0x18ClearFlag0x1((unsigned char*)obj, fields.v);
        obj->ptr->flags20 = flags20;
        if (flags20 & 0x21) {
            _ZN8Vector3iaSERKS_(obj->vec44, fields.v);
        }
    }
    SetSubstructByte0x1c((unsigned char*)obj, cell & 0xff);
    SetSubstructByte0x1d((unsigned char*)obj, 0xff);
    if (flag == 0) {
        SetSubstructByte0x1e((unsigned char*)obj, 0xff);
    }
    if (obj->b_be == 0) {
        SetByte0xbeShiftPrev((Bytes02033b88*)obj, 0);
        ((Object3D*)obj)->IsTransitioningAnimations();
    }
    ((Object3D*)obj)->SetAnimationPlaybackSpeed(0x1000, 0);
    ResetInnerState02048c90((Obj02048c90*)obj);
}
