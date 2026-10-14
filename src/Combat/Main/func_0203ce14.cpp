#include <globaldefs.h>

struct Vec3s32_020c3030 { int x; int y; int z; };
struct Vec3 { int x; int y; int z; };
struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Struct_203cdd8 { char pad[0x64]; int value; };

extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" ARM int fix32_Divide(unsigned int numerHi, unsigned int denomLo);
struct Vector3i;
ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);
extern "C" int fix32_Atan2(int x, int z);
void SetField0x64RoundedTo256(struct Struct_203cdd8* obj, int value);

// USA: func_0203ce14
extern "C" ARM void func_0203ce14(void* obj, struct Vec3s32_020c3030* target) {
    char* base = (char*)obj;
    int dist = Vector3fix_Distance(target, (struct Vec3s32_020c3030*)(base + 0x4));
    if (dist == 0) {
        return;
    }
    _ZN8Vector3iaSERKS_((int*)(base + 0x78), (int*)target);
    int flags = *(int*)(base + 0x5c);
    flags |= 1;
    *(int*)(base + 0x5c) = flags;
    if (flags & 4) {
        return;
    }
    struct Vec3 diff;
    Vector3fix_Subtract((struct Vec3*)(base + 0x78), (struct Vec3*)(base + 0x4), &diff);
    int scale = fix32_Divide(0x1000, dist);
    Vector3fixMultiplyScalar((Vector3i const*)&diff, scale, (Vector3i*)&diff);
    int angle = fix32_Atan2(diff.x, diff.z);
    SetField0x64RoundedTo256((struct Struct_203cdd8*)obj, angle);
}
