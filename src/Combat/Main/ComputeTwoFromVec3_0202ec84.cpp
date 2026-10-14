#include <globaldefs.h>

struct Vector3i;
int ConvertWorldToScreenCoordinates(Vector3i const*, int*, int*);

struct Vec3copy0202ec84 {
    unsigned int v[3];
};

// USA: func_0202ec84
ARM int ComputeTwoFromVec3_0202ec84(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2) {
    struct Vec3copy0202ec84 local = *src;
    int a, b;
    int result = ConvertWorldToScreenCoordinates((Vector3i const*)&local, &a, &b);
    *out1 = a;
    *out2 = b;
    return result;
}
