#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };
struct Vec3s32_020c3030 { int x; int y; int z; };
struct Vec3Fixed02030e2c { int x; int y; int z; };
struct Target02059f38;
struct Vec3_02059f38;

void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src);
struct Vector3i;
void Vector3fixMultiplyScalar(Vector3i const*, int, Vector3i*);

struct MoveRequest_021eeb8c {
    char pad0[8];
    unsigned short combatantId;
    unsigned short remaining;
    struct Vec3 target;
};

struct PosHolder_021eeb8c { char pad[0x44]; struct Vec3 pos; };

// USA: func_ov025_021eeb8c  (semantic: MoveTowardTargetOverTime_021eeb8c)
extern "C" ARM int func_ov025_021eeb8c(struct MoveRequest_021eeb8c* req) {
    GameState* battle = GameState::GetInstance();
    int elapsed = battle->GetEffectiveDeltaTime();
    GameObject* combatant = battle->GetGameObjectByIndex(req->combatantId);
    if (!combatant) return 1;
    if (req->remaining <= (unsigned int)elapsed) {
        CopyVec3ToField0x44((struct Target02059f38*)combatant, (struct Vec3_02059f38*)&req->target);
        return 1;
    }
    struct Vec3 curPos = ((struct PosHolder_021eeb8c*)combatant)->pos;
    int dist = Vector3fix_Distance((const Vector3fix*)((struct Vec3s32_020c3030*)&curPos), (const Vector3fix*)((struct Vec3s32_020c3030*)&req->target));
    float ratio = (float)(unsigned int)elapsed / (float)req->remaining;
    int step = (int)(((long long)dist * (int)(ratio * 4096.0f) + 0x800) >> 12);
    struct Vec3 diff;
    Vector3fix_Subtract((const Vector3fix*)&req->target, (const Vector3fix*)&curPos, (Vector3fix*)&diff);
    int scale2 = fix32_Divide((fix32_t)step, (fix32_t)dist);
    Vector3fixMultiplyScalar((Vector3i const*)&diff, scale2, (Vector3i*)&diff);
    Vector3fix_Add((const Vector3fix*)&curPos, (const Vector3fix*)&diff, (Vector3fix*)&curPos);
    CopyVec3ToField0x44((struct Target02059f38*)combatant, (struct Vec3_02059f38*)&curPos);
    req->remaining -= elapsed;
    return 0;
}
