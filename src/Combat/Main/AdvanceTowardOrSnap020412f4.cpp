#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Vec3Fixed02030e2c {
    int x;
    int y;
    int z;
};

struct Struct02041538;

extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
extern "C" int Vector3fix_Length(int* v);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" int fix32_Divide(unsigned int numerHi, unsigned int denomLo);
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);
void RefreshSelectionState02041538(struct Struct02041538* self);

struct MoveObj020412f4 {
    char pad0[0x44];
    struct Vec3 pos;
    char pad1[0xb4 - 0x50];
    struct Vec3 target;
    char pad2[0xc8 - 0xc0];
    int step;
};

// USA: func_020412f4  (semantic: AdvanceTowardOrSnap020412f4)
extern "C" ARM void func_020412f4(struct MoveObj020412f4* obj) {
    struct Vec3 diff;
    Vector3fix_Subtract(&obj->target, &obj->pos, &diff);
    int length = Vector3fix_Length((int*)&diff);
    if (obj->step < length) {
        int scale = fix32_Divide(obj->step, length);
        Vector3fixMultiplyScalar((Vector3i const*)&diff, scale, (Vector3i*)&diff);
        struct Vec3 sum;
        Vector3fix_Add(&obj->pos, &diff, &sum);
        _ZN8Vector3iaSERKS_((int*)&obj->pos, (int*)&sum);
    } else {
        _ZN8Vector3iaSERKS_((int*)&obj->pos, (int*)&obj->target);
        RefreshSelectionState02041538((struct Struct02041538*)obj);
    }
}
