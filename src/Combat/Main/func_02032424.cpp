#include <globaldefs.h>

struct Vector3fix
{
    int x;
    int y;
    int z;
};

extern "C" void Vector3fix_Subtract(const Vector3fix* a, const Vector3fix* b, Vector3fix* out);   // called at +0x18  (0x020c2dc4)
extern "C" void Vector3fix_Normalize(const Vector3fix* in, Vector3fix* out);   // called at +0x24  (0x020c2f18)
extern "C" int fix32_Atan2(int y, int x);   // called at +0x38  (0x020c338c)
int fix32ReduceAngle0To2Pi(int);   // called at +0x3c  (0x02030f30)

// USA: func_02032424
extern "C" ARM int func_02032424(const Vector3fix* source, const Vector3fix* target) {
    Vector3fix delta;
    Vector3fix_Subtract(target, source, &delta);
    Vector3fix_Normalize(&delta, &delta);
    return fix32ReduceAngle0To2Pi(fix32_Atan2(-delta.x, -delta.z));
}