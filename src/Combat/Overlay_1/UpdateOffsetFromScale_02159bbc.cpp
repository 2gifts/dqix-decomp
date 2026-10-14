#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov001_02164808(int, int, void*);
extern int data_ov001_02165884;

struct Vec3_02159bbc { int x, y, z; };
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct Triple02159b94 { int c, d, e; };
int ForwardTriple_02159b94(int a, int b, struct Triple02159b94 t);

struct A02159bbc { int pad0; Vec3_02159bbc pos; int scale; };
struct B02159bbc { char pad0[0x5c]; int counter; char pad1[0x70 - 0x60]; int fwdVal; char pad2[0x108 - 0x74]; Vec3_02159bbc outVec; };

// USA: func_ov001_02159bbc  (semantic: UpdateOffsetFromScale_02159bbc)
extern "C" ARM int func_ov001_02159bbc(struct A02159bbc* a, struct B02159bbc* b) {
    void* battle = GameState::GetInstance();
    unsigned int scaledCount = ((GameState*)battle)->GetTickCount() << 12;
    int counter = b->counter;
    if (counter >= a->scale * 2) {
        b->counter = 0;
        return 0;
    }
    if (counter <= 0) {
        Vec3_02159bbc delta2;
        Vec3_02159bbc delta1;
        func_ov001_02164808(data_ov001_02165884, b->fwdVal, &delta1);
        int scaleShifted = a->scale << 12;
        Vector3fix_Subtract((const Vector3fix*)&a->pos, (const Vector3fix*)&delta1, (Vector3fix*)&delta2);
        b->outVec.x = fix32_Divide((fix32_t)delta2.x, (fix32_t)scaleShifted);
        b->outVec.y = fix32_Divide((fix32_t)delta2.y, (fix32_t)scaleShifted);
        b->outVec.z = fix32_Divide((fix32_t)delta2.z, (fix32_t)scaleShifted);
    } else {
        Vec3_02159bbc tmp = b->outVec;
        int divScale = fix32_Divide((fix32_t)scaledCount, (fix32_t)(0x2000));
        Vector3fixMultiplyScalar((Vector3i const*)&tmp, divScale, (Vector3i*)&tmp);
        Vec3_02159bbc sum;
        func_ov001_02164808(data_ov001_02165884, b->fwdVal, &sum);
        Vector3fix_Add((const Vector3fix*)&sum, (const Vector3fix*)&tmp, (Vector3fix*)&sum);
        struct Triple02159b94 t = *(struct Triple02159b94*)&sum;
        ForwardTriple_02159b94(data_ov001_02165884, b->fwdVal, t);
    }
    b->counter += ((GameState*)battle)->GetTickCount();
    return 1;
}
