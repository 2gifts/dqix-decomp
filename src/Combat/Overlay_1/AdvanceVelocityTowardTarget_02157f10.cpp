#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };
struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Blk3_02157f10 { int v[3]; };

struct Vector3i;
ARM void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

// USA: func_ov001_02157f10  (semantic: AdvanceVelocityTowardTarget_02157f10)
extern "C" ARM int func_ov001_02157f10(void* a, void* b) {
    char* pA = (char*)a;
    char* pB = (char*)b;
    GameState* battleStruct = GameState::GetInstance();
    int scale = battleStruct->GetTickCount() << 0xc;
    int period = *(int*)(pA + 0x1c);
    if (period == 0) {
        memcpy(pB + 0x4c, pA + 0x4, 0xc);
        *(int*)(pB + 0x38) = 0;
        return 0;
    }
    if (*(int*)(pB + 0x38) <= 0) {
        struct Vec3 diff;
        int denom = period << 0xd;
        Vector3fix_Subtract((const Vector3fix*)((struct Vec3*)(pA + 0x4)), (const Vector3fix*)((struct Vec3*)(pB + 0x4c)), (Vector3fix*)&diff);
        *(int*)(pB + 0xb4) = fix32_Divide((fix32_t)diff.x, (fix32_t)denom);
        *(int*)(pB + 0xb8) = fix32_Divide((fix32_t)diff.y, (fix32_t)denom);
        *(int*)(pB + 0xbc) = fix32_Divide((fix32_t)diff.z, (fix32_t)denom);
    }
    struct Blk3_02157f10 vel = *(struct Blk3_02157f10*)(pB + 0xb4);
    Vector3fixMultiplyScalar((Vector3i const*)&vel, scale, (Vector3i*)&vel);
    Vector3fix_Add((const Vector3fix*)((struct Vec3*)(pB + 0x4c)), (const Vector3fix*)((struct Vec3*)&vel), (Vector3fix*)((struct Vec3*)(pB + 0x4c)));
    int counter = *(int*)(pB + 0x38) + battleStruct->GetTickCount();
    *(int*)(pB + 0x38) = counter;
    int limit = *(int*)(pA + 0x1c) << 1;
    if (counter >= limit) {
        *(int*)(pB + 0x38) = 0;
        return 0;
    }
    return 1;
}
