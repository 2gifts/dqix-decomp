#include <globaldefs.h>

struct Vec3 { int x, y, z; };
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Normalize(struct Vec3* a, struct Vec3* b);
extern "C" int fix32_Atan2(int x, int z);
int fix32SignedAngleDistance(int a, int b);

// USA: func_ov017_021a4700
ARM short GetAngleDeltaBetween_021a4700(struct Vec3* p0, int baseAngle, struct Vec3* p2) {
    struct Vec3 local;
    Vector3fix_Subtract(p2, p0, &local);
    Vector3fix_Normalize(&local, &local);
    int angle = fix32_Atan2(local.x, local.z);
    return (short)fix32SignedAngleDistance(baseAngle, angle);
}
