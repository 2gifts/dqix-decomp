#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Vec4f {
    int x;
    int y;
    int z;
    int w;
};

extern "C" short _Z8fix32cosi(int x);
extern "C" short _Z8fix32sini(int x);
extern "C" void Vector3fix_Normalize(struct Vec3* v, struct Vec3* out);
extern "C" int Vector3fix_InnerProduct(struct Vec3* a, struct Vec3* b);

struct Obj020322c0 {
    char pad0[0x24];
    struct Vec3 f24;
};

// USA: func_020322c0
extern "C" ARM int func_020322c0(const struct Obj020322c0* self, const struct Vec4f* other) {
    struct Vec3 a = self->f24;
    Vector3fix_Normalize(&a, &a);

    int cz = _Z8fix32cosi(other->x);
    struct Vec3 dir;
    dir.x = _Z8fix32sini(other->x);
    dir.y = 0;
    dir.z = cz;
    Vector3fix_Normalize(&dir, &dir);

    return Vector3fix_InnerProduct(&dir, &a);
}
