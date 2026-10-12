#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Matrix.h>

struct Obj02033b68;
struct Obj02033834;
struct Obj02033874;
struct Foo02033b58;
struct ActorFlags { unsigned int bits; };
struct TrailPoint { int x, z; };
struct FollowingActor {
    Object3D object;
    short movementFlag;
    unsigned char field_0xae[6];
    unsigned short animation;
    unsigned char field_0xb6[8];
    unsigned char state;
    unsigned char field_0xbf;
    unsigned char behavior;
    unsigned char field_0xc1[0x6f];
    ActorFlags* flags;
    unsigned char field_0x134[0x94];
    signed char partyIndex;
    unsigned char field_0x1c9;
    signed char targetIndex;
    signed char writeIndex;
    signed char readIndex;
    unsigned char queued;
    unsigned char followFlags;
    unsigned char field_0x1cf;
    TrailPoint trail[16];
    unsigned char field_0x250[0x18];
    int fade;
    unsigned char followerEnabled;
    unsigned char targetMode;
};

extern "C" void func_ov017_021917f0(int, int);
void SetByteIfChanged02033b68(Obj02033b68*, int);
int fix32ReduceAngle0To2Pi(int);
void SetVecYByMode02033834(Obj02033834*, int);
void ClearBytesAndZeroBlock02039d24(unsigned char*);
void SetByteSavingPrevious(Foo02033b58*, unsigned char);
int IsField0Null(void**);
void SetVecYFromValue02033874(Obj02033874*, int);

// USA: func_020391ac
extern "C" ARM void func_020391ac(FollowingActor* actor) {
    GameState* game;
    FollowingActor* leader;
    FollowingActor* target;
    int moving;
    int separation;
    int trailDistance;
    int spacing;
    int gap;
    int threshold;
    int ready;
    int angle;
    int previousIndex;
    void** resource;
    if (actor->followFlags & 1)
        return;
    resource = (void**)func_ov017_0218b5b0()->unknown_ptr_array_36fc[0];
    game = GameState::GetInstance();
    leader = (FollowingActor*)game->GetPartyMemberByIndex(actor->partyIndex);
    target = (FollowingActor*)game->GetPartyMemberByIndex(actor->targetIndex);
    if (leader == 0 || target == 0)
        return;
    if (leader->state == 2) {
        if (actor->state != 2) {
            func_ov017_021917f0(actor->object.unknown_4_, 1);
        }
        SetByteIfChanged02033b68((Obj02033b68*)actor, 2);
        return;
    }
    if (actor->state == 2) {
        func_ov017_021917f0(actor->object.unknown_4_, 0);
        SetByteIfChanged02033b68((Obj02033b68*)actor, 0);
    }
    if (target->followerEnabled) {
        if (target->targetMode == 0 || target->targetMode == 1 || target->targetMode == 2) {
            Vector3fix origin = actor->object.position_;
            origin.y = 0;
            Vector3fix destination = target->object.position_;
            destination.y = 0;
            Vector3fix direction;
            Vector3fix_Subtract(&destination, &origin, &direction);
            int distance = Vector3fix_Length(&direction);
            Vector3fix_Normalize(&direction, &direction);
            SetVecYByMode02033834((Obj02033834*)actor, fix32ReduceAngle0To2Pi(fix32_Atan2(direction.x, direction.z)));
            if (distance < 0x1000)
                SetByteIfChanged02033b68((Obj02033b68*)actor, 0);
            else {
                actor->animation = 0x189;
                SetByteIfChanged02033b68((Obj02033b68*)actor, 1);
            }
            actor->object.SetInheritedAlpha(31 - actor->fade);
            actor->followFlags &= ~4;
            actor->fade += (int)(1.5f * game->GetTickCount());
            if (actor->fade > 31)
                actor->fade = 31;
        } else if (target->targetMode == 3 || target->targetMode == 4 || target->targetMode == 5) {
            actor->fade = 0;
            actor->object.position_ = target->object.position_;
            actor->object.SetInheritedAlpha(31);
            ClearBytesAndZeroBlock02039d24((unsigned char*)actor);
            SetByteIfChanged02033b68((Obj02033b68*)actor, 0);
            actor->followFlags |= 4;
        }
        return;
    }
    actor->fade = 0;
    Vector3fix leaderPosition = leader->object.position_;
    leaderPosition.y = 0;
    Vector3fix actorPosition = actor->object.position_;
    actorPosition.y = 0;
    separation = Vector3fix_Distance(&actorPosition, &leaderPosition);
    if (actor->queued == 0) {
        switch (leader->behavior) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            actor->queued = 1;
            actor->trail[actor->writeIndex].x = leaderPosition.x;
            actor->trail[actor->writeIndex].z = leaderPosition.z;
            break;
        }
    }
    if (actor->queued == 0) {
        SetByteSavingPrevious((Foo02033b58*)actor, 0);
        return;
    }
    moving = actor->movementFlag != 0;
    Vector3fix previous = {0, 0, 0};
    previousIndex = actor->writeIndex;
    previous.x = actor->trail[previousIndex].x;
    previous.z = actor->trail[previousIndex].z;
    trailDistance = Vector3fix_Distance(&leaderPosition, &previous);
    spacing = 0x800;
    if ((actor->flags->bits & 1) && (leader->flags->bits & 1)) {
        int pending = actor->writeIndex - actor->readIndex;
        if (pending < 0)
            pending = 16 - actor->readIndex + actor->writeIndex;
        if (pending <= 2)
            spacing = 0xe66;
    }
    if (trailDistance > spacing) {
        ++actor->writeIndex;
        actor->writeIndex %= 16;
        actor->trail[actor->writeIndex].x = leaderPosition.x;
        actor->trail[actor->writeIndex].z = leaderPosition.z;
    }
    if (actor->writeIndex < 0)
        return;
    gap = actor->writeIndex - actor->readIndex;
    if (gap < 0)
        gap = 16 - actor->readIndex + actor->writeIndex;
    if (gap > 2)
        actor->animation = 0x24d;
    else if (gap <= 1)
        actor->animation = 0x9d;
    else
        actor->animation = 0x189;
    threshold = spacing + 0xb33;
    ready = 1;
    if (!IsField0Null(resource))
        ready = 0;
    if (gap >= 1 || (separation > threshold && ready) || moving) {
        Vector3fix origin = actor->object.position_;
        origin.y = 0;
        Vector3fix destination = {0, 0, 0};
        destination.x = actor->trail[actor->readIndex].x;
        destination.z = actor->trail[actor->readIndex].z;
        Vector3fix direction;
        Vector3fix_Subtract(&destination, &origin, &direction);
        int distance = Vector3fix_Length(&direction);
        Vector3fix_Normalize(&direction, &direction);
        angle = fix32ReduceAngle0To2Pi(fix32_Atan2(direction.x, direction.z));
        if (moving)
            SetVecYFromValue02033874((Obj02033874*)actor, leader->object.rotation_.y);
        else
            SetVecYByMode02033834((Obj02033834*)actor, angle);
        if (distance <= 0x800 && actor->readIndex != actor->writeIndex) {
            ++actor->readIndex;
            actor->readIndex %= 16;
        }
        if (moving)
            SetByteIfChanged02033b68((Obj02033b68*)actor, 0);
        else if (actor->state != 1)
            SetByteIfChanged02033b68((Obj02033b68*)actor, 1);
    } else if (actor->state != 0)
        SetByteIfChanged02033b68((Obj02033b68*)actor, 0);
}
