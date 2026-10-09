#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Util/Random.h"

struct BattleCamera {
    unsigned char padding0[0x10];
    Vector3i target;
    unsigned char padding1c[0x200];
    Random* battle;
    unsigned char padding220[0x18];
    int mode;
    unsigned char padding23c[0x3c];
    unsigned char active;
};
struct CameraCombatant {
    Object3D object;
    unsigned char paddingac[0x16];
    unsigned char flags : 4;
    unsigned char included : 1;
};
struct Vec3Ints0216d368 { int x, y, z; };
struct GlobalObj0202e6a8;
extern "C" void func_ov000_0216d370(BattleCamera*, int, int, int);
extern "C" int func_ov000_0215e9fc(Random*, short*, int, int);
extern "C" void func_0202e5d8(BattleCamera*, int, int, int);
CameraCombatant* GetCombatantWithFlag0x400(GameState*, int);
void SetFields0x10To0x18(unsigned char*, int, int, int);
extern "C" void _Z22StoreVec3Words0216d368P16Vec3Ints0216d368iii(Vec3Ints0216d368*, int, int, int);
void ApplyField0x70Tail(GlobalObj0202e6a8*, int);

// USA: func_ov000_0216e3c4
extern "C" ARM void func_ov000_0216e3c4(BattleCamera* camera) {
    if (!camera->battle) return;
    GameState* game = GameState::GetInstance();
    func_ov000_0216d370(camera, 1, 1, 1);
    GameObject* protagonist = game->GetProtagonist();
    int group = -1;
    if (protagonist) group = protagonist->obj3D_.GetField06();
    short ids[4];
    int count = func_ov000_0215e9fc(camera->battle, ids, 4, 0);
    Vector3i center = {};
    int accepted = 0;
    for (int i = 0; i < count; i++) {
        GameObject* object = game->GetGameObjectByIndex(ids[i]);
        if (object && group == object->obj3D_.GetField06()) {
            Vector3i position = object->obj3D_.position_;
            Vector3fix_Add(&center, &position, &center);
            accepted++;
        }
    }
    if (accepted > 0) {
        int scale = fix32_Divide(0x1000, accepted << 12);
        Vector3fixMultiplyScalar(&center, scale, &center);
    }
    int distance = 0xc000 - Vector3fix_Length(&center);
    if (distance < 0x8000) {
        int scale = fix32_Divide(distance, 0x8000);
        Vector3fixMultiplyScalar(&center, scale, &center);
        distance = 0xc000;
    }
    int angle = 0;
    count = func_ov000_0215e9fc(camera->battle, ids, 4, 1);
    if (count > 0) {
        int selected = NextRandomMax(camera->battle, count);
        GameObject* object = game->GetGameObjectByIndex(ids[selected]);
        if (object) angle = object->obj3D_.rotation_.y;
    }
    angle = fix32ReduceAngle0To2Pi(angle - 0x648);
    SetFields0x10To0x18((unsigned char*)camera, center.x, 0x800, center.z);
    func_0202e5d8(camera, angle, 0x1000, distance);
    int combatants = 0;
    camera->mode = 14;
    camera->active = 1;
    Vec3Ints0216d368 sum;
    _Z22StoreVec3Words0216d368P16Vec3Ints0216d368iii(&sum, 0, 0, 0);
    for (int i = 0; i < 8; i++) {
        CameraCombatant* object = GetCombatantWithFlag0x400(game, i + 0xc0);
        if (object && object->included) {
            Vector3i position;
            position = object->object.position_;
            Vector3fix_Add(&position, (Vector3i*)&sum, (Vector3i*)&sum);
            combatants++;
        }
    }
    if (combatants) {
        int scale = fix32_Divide(0x1000, combatants << 12);
        Vector3fixMultiplyScalar((Vector3i*)&sum, scale, (Vector3i*)&sum);
        Vector3i current;
        current = camera->target;
        int facing = fix32_Atan2_Rescaled(sum.z - current.z, sum.x - current.x);
        ApplyField0x70Tail((GlobalObj0202e6a8*)camera, -0x999 + ((facing / 0xffff) << 12));
    }
}
