#include <globaldefs.h>

typedef signed long long int64_t;
typedef int fix32_t;

class Object3D
{
public:
    char pad0[0xac];
    void SetScale(fix32_t x, fix32_t y, fix32_t z);
};

extern "C" fix32_t fix32_Divide(fix32_t num, fix32_t denom);

static inline fix32_t FX_Mul(fix32_t a, fix32_t b)
{
    return (fix32_t)(((int64_t)a * b + 0x800) >> 12);
}

enum
{
    Part_Body,
    Part_1,
    Part_2,
    Part_3,
    Part_4,
    Part_5,
    Part_6,
    Part_7,
    Part_8,
    Part_9
};

struct CharacterModel_021e5e68
{
    Object3D parts_[10];
};

// USA: func_ov023_021e5e68
extern "C" ARM void func_ov023_021e5e68(CharacterModel_021e5e68* self, int width, int height)
{
    fix32_t scale = FX_Mul(height, width);
    self->parts_[Part_Body].SetScale(scale, height, scale);
    self->parts_[Part_6].SetScale(scale, height, scale);
    self->parts_[Part_1].SetScale(scale, height, scale);
    self->parts_[Part_5].SetScale(scale, height, scale);

    short inverse = fix32_Divide(0x1000, scale);
    short inverseHeight = fix32_Divide(0x1000, height);
    self->parts_[Part_8].SetScale(inverse, inverseHeight, inverse);
    self->parts_[Part_9].SetScale(inverse, inverseHeight, inverse);

    short x = FX_Mul(inverse, 0x1000);
    short y = FX_Mul(inverseHeight, 0x1000);
    short z = FX_Mul(0x1000, inverse);
    self->parts_[Part_2].SetScale(x, y, z);
    self->parts_[Part_3].SetScale(x, y, z);
    self->parts_[Part_7].SetScale(x, y, z);
}
