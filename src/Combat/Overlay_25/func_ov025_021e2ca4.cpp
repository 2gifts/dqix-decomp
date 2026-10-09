#include <globaldefs.h>
#include "GameState/GameState.h"

struct ListNode02160094 { char pad0[0x20]; unsigned short id; };
struct ListNode021600f8 { char pad0[0xe]; short id; };
struct List02160094 { char pad0[0x10]; ListNode02160094* head; };
struct List021600f8;
struct MovementCommand { char pad0[8]; short start; short end; int margin; };
struct Rec021eee48 {
    int type;
    int delay;
    unsigned short id;
    unsigned short duration;
    union { Vector3i position; unsigned short angle; } target;
    Rec021eee48* next;
};
struct Obj021eee48;
extern "C" ListNode02160094* _Z22GetNodeAtIndex02160094P12List02160094i(List02160094*, int);
extern "C" ListNode021600f8* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8*, int);
extern "C" void _Z20ResetFields_021de110Pv(void*);
extern "C" void _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(Obj021eee48*, Rec021eee48*);
extern "C" int func_ov025_021df9f4(GameObject*);
extern "C" void func_02033920(GameObject*, int, int);

// USA: func_ov025_021e2ca4
extern "C" ARM int func_ov025_021e2ca4(MovementCommand* command, List02160094* list, Obj021eee48* queue) {
    ListNode02160094* node = _Z22GetNodeAtIndex02160094P12List02160094i(list, 0);
    if (!node) return 0;
    int id = node->id;
    GameState* game = GameState::GetInstance();
    GameObject* actor = game->GetCombatantByIndex(id);
    BCFG* config = actor->obj3D_.GetCurrentAnimationConfig();
    int animation = actor->obj3D_.activeAnimationIndex_;
    if (!config) return 1;
    BCFG::AnimationRecord* record = config->GetAnimationRecord(animation);
    if (!record) return 0;
    ListNode021600f8* target = _Z22GetNodeAtIndex021600f8P12List021600f8i((List021600f8*)list, 0);
    if (!target) return 1;
    GameObject* other = game->GetCombatantByIndex(target->id);
    if (record && other) {
        int time = (int)(16.666f * (float)fix32_Divide(record->endTime - record->startTime, record->frameRate) / 4096.0f);
        short start = command->start;
        int duration = (int)((float)time * ((float)(command->end - start) / 4096.0f));
        int delay = 0;
        if (actor->obj3D_.normalizedAnimationTime_ < start) {
            delay = (int)(((long long)time * (start - actor->obj3D_.normalizedAnimationTime_) + 0x800) >> 12);
        }
        Vector3fix targetPosition = other->obj3D_.position_;
        Vector3fix actorPosition = actor->obj3D_.position_;
        int actorRadius = actor->obj3D_.GetRadius() / 2;
        int targetRadius = other->obj3D_.GetRadius() / 2;
        int distance = Vector3fix_Distance(&actorPosition, &targetPosition) - actorRadius - targetRadius - command->margin;
        Vector3fix direction;
        Vector3fix_Subtract(&targetPosition, &actorPosition, &direction);
        Vector3fix_Normalize(&direction, &direction);
        Vector3fix movement;
        Vector3fixMultiplyScalar(&direction, distance, &movement);
        Vector3fix destination;
        Vector3fix_Add(&actorPosition, &movement, &destination);
        Rec021eee48 entry;
        _Z20ResetFields_021de110Pv(&entry);
        entry.type = 0;
        entry.delay = delay;
        entry.id = node->id;
        entry.duration = duration;
        entry.target.position = destination;
        _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(queue, &entry);
        int angle = fix32_Atan2(direction.x, direction.z);
        int turnDuration = 250;
        if (duration < turnDuration) turnDuration = duration;
        entry.type = 1;
        entry.duration = turnDuration;
        entry.target.angle = angle;
        if (list->head) entry.id = list->head->id;
        else entry.id = 0;
        _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(queue, &entry);
        entry.type = 1;
        entry.id = node->id;
        entry.duration = duration;
        entry.target.angle = fix32_Atan2(direction.x, direction.z);
        _Z29PushNodeFromFreeList_021eee48P11Obj021eee48P11Rec021eee48(queue, &entry);
        if (func_ov025_021df9f4(other)) func_02033920(other, node->id, 1);
    }
    return 1;
}
