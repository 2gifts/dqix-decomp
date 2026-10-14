#include <globaldefs.h>

struct S020a3570;
struct GlobalObj0202e6a8;
struct Obj0202e71c;

extern "C" void func_020a2d14(void* obj);
int GetField0x218(struct S020a3570* p);
extern "C" void func_ov000_0216f3d4(void* obj);
extern "C" void func_ov000_0216ea38(void* obj);
extern "C" void func_ov000_0216f0d0(void* obj);
int GetField0x70(void* obj);
int fix32ReduceAngle0To2Pi(int angle);
void ApplyField0x70Tail(struct GlobalObj0202e6a8* obj, int value);
int GetField0x78(void* obj);
void SetField78Clamped0202e71c(struct Obj0202e71c* obj, int p);
extern "C" void func_ov000_0216f2b8(void* obj);

struct Struct0216d464 {
    unsigned char pad[0x238];
    int f238;
    int f23c;
};

// USA: func_ov000_0216d464
extern "C" ARM void func_ov000_0216d464(struct Struct0216d464* obj) {
    func_020a2d14(obj);
    if (GetField0x218((struct S020a3570*)obj) != 0) {
        func_ov000_0216f3d4(obj);
        return;
    }
    func_ov000_0216ea38(obj);
    func_ov000_0216f0d0(obj);
    if (obj->f238 != 0) {
        int a = GetField0x70(obj);
        int angle = fix32ReduceAngle0To2Pi(a + obj->f238);
        ApplyField0x70Tail((struct GlobalObj0202e6a8*)obj, angle);
    }
    if (obj->f23c != 0) {
        int cur78 = GetField0x78(obj);
        int f23c = obj->f23c;
        int limit = (f23c < cur78) ? (cur78 + f23c) : 0;
        if (limit < 0x3000) {
            limit = 0x3000;
        }
        SetField78Clamped0202e71c((struct Obj0202e71c*)obj, limit);
    }
    func_ov000_0216f2b8(obj);
    func_ov000_0216f3d4(obj);
}
