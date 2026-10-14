#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

extern "C" void __clear(void* ptr, int size);
extern "C" float _ffltu(unsigned int v);
extern "C" void Vector3fix_Normalize(struct Vec3* a, struct Vec3* b);
extern "C" int fix32_Atan2(int x, int z);
int fix32ReduceAngle0To2Pi(int angle);
short fix32sin(int x);
short fix32cos(int x);

struct Touch02096a20 {
    char pad[0x220];
    unsigned char startX;
    unsigned char startY;
    unsigned char x;
    unsigned char y;
    char pad2[4];
    short dirX;
    short dirY;
    short dirZ;
    short angle;
};

extern const int data_0210a05c[256];

// USA: func_02096a20
extern "C" ARM void func_02096a20(struct Touch02096a20* self) {
    struct Vec3 delta;
    struct Vec3 ref;

    __clear(&delta, 0xc);
    delta.x = (int)(((float)self->x - (float)self->startX > 0.0f)
                    ? 0.5f + 4096.0f * ((float)self->x - (float)self->startX)
                    : 4096.0f * ((float)self->x - (float)self->startX) - 0.5f);
    delta.z = (int)(((float)self->y - (float)self->startY > 0.0f)
                    ? 0.5f + 4096.0f * ((float)self->y - (float)self->startY)
                    : 4096.0f * ((float)self->y - (float)self->startY) - 0.5f);
    Vector3fix_Normalize(&delta, &delta);

    const int* g = (const int*)&data_0210a05c;
    __clear(&ref, 0xc);
    ref.x = g[6];
    ref.z = g[8];
    Vector3fix_Normalize(&ref, &ref);

    short fwd = (short)fix32ReduceAngle0To2Pi(fix32_Atan2(delta.x, delta.z));
    short rev = (short)fix32ReduceAngle0To2Pi(-fix32_Atan2(ref.x, ref.z));

    self->angle = (short)fix32ReduceAngle0To2Pi(fwd + rev);
    self->dirX = fix32sin(self->angle);
    self->dirY = 0;
    self->dirZ = fix32cos(self->angle);
}
