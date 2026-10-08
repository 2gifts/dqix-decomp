#include <globaldefs.h>

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

extern "C" int _Z20GetSubstructByte0x1ePh(struct Obj02048cf0* obj);
extern "C" int _Z20GetSubstructByte0x1dPh(struct Obj02048cf0* obj);
extern "C" int _Z20GetSubstructByte0x1cPh(struct Obj02048cf0* obj);
extern "C" void _Z20SetSubstructByte0x1cPhh(struct Obj02048cf0* obj, unsigned char v);
extern "C" void _Z20SetSubstructByte0x1dPhh(struct Obj02048cf0* obj, unsigned char v);
extern "C" void _Z20SetSubstructByte0x1ePhh(struct Obj02048cf0* obj, unsigned char v);
extern "C" void _Z41SetSubstructFields0x10And0x18ClearFlag0x1PhPi(struct Obj02048cf0* obj, int* src);
extern "C" void _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(struct Obj02048cf0* obj, int v);
extern "C" int _ZNK8Object3D25IsTransitioningAnimationsEv(struct Obj02048cf0* obj);
extern "C" void _ZN8Object3D25SetAnimationPlaybackSpeedEsi(struct Obj02048cf0* obj, short a, short b);
extern "C" void _Z23ResetInnerState02048c90P11Obj02048c90(struct Obj02048cf0* obj);
extern "C" struct Vec2_0216f74c func_ov000_0216f74c(int* in);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

extern Vec3_02048cf0 data_020e7b48;

// USA: func_02048cf0
extern "C" ARM void func_02048cf0(struct Obj02048cf0* obj, int flag) {
    int cell = _Z20GetSubstructByte0x1ePh(obj);
    if (cell == 0xff) {
        cell = _Z20GetSubstructByte0x1dPh(obj);
    }
    if (cell == 0xff) {
        cell = _Z20GetSubstructByte0x1cPh(obj);
    }
    if (flag != 0) {
        cell = _Z20GetSubstructByte0x1cPh(obj);
    }
    if (cell != 0xff) {
        struct Vec2_0216f74c pos = func_ov000_0216f74c(&cell);
        struct Vec3_02048cf0 fields = data_020e7b48;
        fields.v[0] = pos.x;
        fields.v[2] = pos.y;
        unsigned int flags20 = obj->ptr->flags20;
        _Z41SetSubstructFields0x10And0x18ClearFlag0x1PhPi(obj, fields.v);
        obj->ptr->flags20 = flags20;
        if (flags20 & 0x21) {
            _ZN8Vector3iaSERKS_(obj->vec44, fields.v);
        }
    }
    _Z20SetSubstructByte0x1cPhh(obj, cell & 0xff);
    _Z20SetSubstructByte0x1dPhh(obj, 0xff);
    if (flag == 0) {
        _Z20SetSubstructByte0x1ePhh(obj, 0xff);
    }
    if (obj->b_be == 0) {
        _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(obj, 0);
        _ZNK8Object3D25IsTransitioningAnimationsEv(obj);
    }
    _ZN8Object3D25SetAnimationPlaybackSpeedEsi(obj, 0x1000, 0);
    _Z23ResetInnerState02048c90P11Obj02048c90(obj);
}