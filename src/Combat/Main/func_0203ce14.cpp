#include <globaldefs.h>
#include "System/Matrix.h"

struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Struct_203cdd8 { char pad[0x64]; int value; };

ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);
void SetField0x64RoundedTo256_0203cdd8(struct Struct_203cdd8* obj, int value);

// USA: func_0203ce14
extern "C" ARM void func_0203ce14(void* obj, Vector3i* target) {
    char* base = (char*)obj;
    int dist = Vector3fix_Distance(target, (Vector3i*)(base + 0x4));
    if (dist == 0) {
        return;
    }
    *(Vector3i*)(base + 0x78) = *target;
    int flags = *(int*)(base + 0x5c);
    flags |= 1;
    *(int*)(base + 0x5c) = flags;
    if (flags & 4) {
        return;
    }
    Vector3i diff;
    Vector3fix_Subtract((Vector3i*)(base + 0x78), (Vector3i*)(base + 0x4), &diff);
    int scale = fix32_Divide(0x1000, dist);
    Vector3fixMultiplyScalar(&diff, scale, &diff);
    int angle = fix32_Atan2(diff.x, diff.z);
    SetField0x64RoundedTo256_0203cdd8((struct Struct_203cdd8*)obj, angle);
}
