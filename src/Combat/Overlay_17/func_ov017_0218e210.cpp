#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Obj02033834;
struct BitFlag02033f44;
struct CollisionNode0218e210 { char pad[0x24]; Vector3fix direction; };
struct Facing0218e210 { char pad[0xae]; short yaw; };
extern "C" void func_02037d88(GameObject*);
int GetField0x397cValue_020100b0(GameState*);
int NotifyEntriesFlag256_0218df50(void*, void*);
extern "C" int func_ov017_0218dfd8(GameObject*);
extern "C" void func_ov017_0219344c(GameObject*, int, const Vector3fix*, int, int*, int*);
CollisionNode0218e210* GetField0xe4IfFlag0x40(BitFlag02033f44*);
int IsFlag0x1ceBit0x8Set_02039dcc(unsigned char*);
void ClearFlag0x1ceBit0x8_02039dbc(unsigned char*);
void SetVecYByMode02033834(Obj02033834*, int);

// USA: func_ov017_0218e210
extern "C" ARM void func_ov017_0218e210(int index, int enabled) {
    GameState* game = GameState::GetInstance();
    GameObject* object = game->GetGameObjectByIndex(index);
    if (!object || object->obj3D_.GetFlag(0x200)) return;
    Vector3fix original = object->obj3D_.position_;
    func_02037d88(object);
    if (!enabled) return;
    Vector3fix current = object->obj3D_.position_;
    int distance = Vector3fix_Distance(&original, &current);
    int id = object->obj3D_.unknown_4_;
    int mode = 1;
    if (id == GetField0x397cValue_020100b0(game) && !(object->obj3D_.unknown_0_ & 0x8000) && distance > 0x333) mode = 2;
    int notified = 0;
    int combined = 0;
    if (mode == 1 && index == GetField0x397cValue_020100b0(game)) {
        notified |= NotifyEntriesFlag256_0218df50(object, 0);
        combined |= notified;
        combined |= func_ov017_0218dfd8(object);
    }
    func_ov017_0219344c(object, 1, &original, mode, &notified, &combined);
    CollisionNode0218e210* node = GetField0xe4IfFlag0x40((BitFlag02033f44*)object);
    int restored = 0;
    int secondNotification = 0;
    if (combined && node) {
        if (!IsFlag0x1ceBit0x8Set_02039dcc((unsigned char*)object)) {
            int handled = 0;
            secondNotification |= NotifyEntriesFlag256_0218df50(object, 0);
            handled |= secondNotification;
            handled |= func_ov017_0218dfd8(object);
            object->obj3D_.position_ = object->obj3D_.position_;
            if (handled) restored = 1;
            if (restored) {
                object->obj3D_.position_ = original;
                if (restored && notified && secondNotification) {
                    int changed = NotifyEntriesFlag256_0218df50(object, 0);
                    object->obj3D_.position_ = original;
                    if (changed) NotifyEntriesFlag256_0218df50(object, (void*)1);
                }
            }
        }
    } else {
        if (!node) ClearFlag0x1ceBit0x8_02039dbc((unsigned char*)object);
        if (node && !IsFlag0x1ceBit0x8Set_02039dcc((unsigned char*)object)) {
            int handled = 0;
            secondNotification |= NotifyEntriesFlag256_0218df50(object, 0);
            handled |= secondNotification;
            handled |= func_ov017_0218dfd8(object);
            object->obj3D_.position_ = object->obj3D_.position_;
            if (handled) {
                restored = 1;
                object->obj3D_.position_ = original;
            }
        }
        if (node && !restored) {
            int rotate = 0;
            int movementAngle;
            if (Vector3fix_Distance(&original, &object->obj3D_.position_) >= 0x28) {
                Vector3fix direction;
                Vector3fix_Subtract(&object->obj3D_.position_, &original, &direction);
                Vector3fix_Normalize(&direction, &direction);
                rotate = 1;
                movementAngle = fix32_Atan2(direction.x, direction.z);
            }
            if (rotate) {
                Vector3fix direction = node->direction;
                direction.y = 0;
                Vector3fix_Normalize(&direction, &direction);
                int collisionAngle = fix32_Atan2(direction.x, direction.z);
                int yaw = ((Facing0218e210*)object)->yaw;
                int difference = fix32SignedAngleDistance(collisionAngle, yaw);
                int magnitude = fix32abs(difference);
                if ((float)magnitude < 10294.4f) {
                    if (magnitude > 0x1922) {
                        if (difference > 0) yaw = fix32ReduceAngle0To2Pi((int)(6772.632f + (float)collisionAngle));
                        else yaw = fix32ReduceAngle0To2Pi((int)((float)collisionAngle - 6772.632f));
                    }
                    if ((float)fix32abs(fix32SignedAngleDistance(yaw, movementAngle)) < 643.4f) SetVecYByMode02033834((Obj02033834*)object, yaw);
                }
            }
        }
    }
    Vector3fix delta;
    Vector3fix_Subtract(&object->obj3D_.position_, &original, &delta);
    if (fix32abs(delta.x) <= 4 && fix32abs(delta.y) <= 4 && fix32abs(delta.z) <= 4) object->obj3D_.position_ = original;
    int moved = Vector3fix_Distance(&original, &object->obj3D_.position_);
    if (distance > 0 && distance < moved) {
        Vector3fix direction;
        Vector3fix_Subtract(&object->obj3D_.position_, &original, &direction);
        Vector3fix_Normalize(&direction, &direction);
        Vector3fixMultiplyScalar(&direction, distance, &direction);
        Vector3fix limited;
        Vector3fix_Add(&original, &direction, &limited);
        object->obj3D_.position_ = limited;
    }
}
