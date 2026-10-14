#include <globaldefs.h>
#include <System/Matrix.h>
#include <Graphics/Vector.h>

struct Combatant020adda4 {
    unsigned char pad_0x00[0x44];
    Vector3fix origin;
    unsigned char pad_0x50[0x5e];
    short tilt;
    unsigned char pad_0xb0[0xb4];
    Vector3fix pivot;
    fix32_t bearing;
    Vector3fix pivot2;
    fix32_t bearing2;
};

struct Vector3i;
ARM void Vector3fixMultiplyScalar(const Vector3fix* in, fix32_t scale, Vector3fix* out);

// USA: func_020adda4
extern "C" ARM void func_020adda4(Combatant020adda4* self) {
    Vector3fix pos = self->origin;
    Vector3fix step;
    Vector3fix aim;
    Vector3fix dir;
    Vector3fix aim2;
    Vector3fix goal;
    Vector3fix goal2;
    short pitch = self->tilt;
    int cz;
    int sx;

    cz = fix32cos(pitch);
    sx = fix32sin(pitch);
    aim.y = 0;
    aim.z = cz;
    aim.x = sx;

    cz = fix32cos(self->bearing);
    sx = fix32sin(self->bearing);
    dir.y = 0;
    dir.z = cz;
    dir.x = sx;

    cz = fix32cos(self->bearing2);
    sx = fix32sin(self->bearing2);
    aim2.y = 0;
    aim2.z = cz;
    aim2.x = sx;

    Vector3fix_Normalize(&aim, &aim);
    Vector3fix_Normalize(&dir, &dir);
    Vector3fix_Normalize(&aim2, &aim2);

    *(Vector3i*)((int*)&step) = *(Vector3i const*)((int*)&aim);
    Vector3fixMultiplyScalar(&step, 0xe66, &step);
    Vector3fix_Subtract(&pos, &step, &goal);
    Vector3fix_Subtract(&goal, &self->pivot, &dir);
    Vector3fix_Normalize(&dir, &dir);

    step.x = -dir.x;
    step.y = -dir.y;
    step.z = -dir.z;
    Vector3fixMultiplyScalar(&step, 0xe66, &step);
    Vector3fix_Add(&goal, &step, &self->pivot);

    self->bearing = fix32_Atan2(dir.x, dir.z);
    self->bearing = fix32ReduceAngle0To2Pi(self->bearing);

    *(Vector3i*)((int*)&step) = *(Vector3i const*)((int*)&dir);
    Vector3fixMultiplyScalar(&step, 0xe66, &step);
    Vector3fix_Subtract(&self->pivot, &step, &goal2);
    Vector3fix_Subtract(&goal2, &self->pivot2, &aim2);
    Vector3fix_Normalize(&aim2, &aim2);

    step.x = -aim2.x;
    step.y = -aim2.y;
    step.z = -aim2.z;
    Vector3fixMultiplyScalar(&step, 0xe66, &step);
    Vector3fix_Add(&goal2, &step, &self->pivot2);

    self->bearing2 = fix32_Atan2(aim2.x, aim2.z);
    self->bearing2 = fix32ReduceAngle0To2Pi(self->bearing2);
}
