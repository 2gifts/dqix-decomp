#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "GameState/GameState.h"

struct Obj02033874;
struct Bytes02033b88;
struct Obj020397cc;
struct Owner020398b4;
void SetVecYFromValue02033874(Obj02033874*, int);
void* GetField0x3f8Address(GameState*);
extern "C" void* func_02012fe4();
void ClearBytesAndZeroBlock02039d24(unsigned char*);
int SetByte0xbeShiftPrev(Bytes02033b88*, int);
void EnqueueEventTag60Field_021d440c(int);
int fix32cos(int);
int fix32sin(int);
void CancelPendingAction020397cc(Obj020397cc*, int);
#if defined(jpn)
#define data_020efb4e data_020efa3e
#endif
extern const char data_020efb4e[];

#if defined(jpn)
enum { kActorTailDelta = 12 };
#else
enum { kActorTailDelta = 0 };
#endif

#define SET_ACTION_POINTS(firstNode, secondNode, reverseValue) \
    block.endNode = secondNode; \
    block.startNode = firstNode; \
    block.start.vec = firstNode->unk_8.vec; \
    block.end.vec = secondNode->unk_8.vec; \
    block.startControl.vec = firstNode->unk_8.vec; \
    block.endControl.vec = secondNode->unk_8.vec; \
    block.startHeading = firstNode->unk_20; \
    block.endHeading = secondNode->unk_20; \
    block.startHeading -= 0x3243; \
    block.reversed = reverseValue; \
    block.endControl.vec.x = direction.x + block.endControl.vec.x; \
    block.endControl.vec.z += direction.z; \
    block.end.vec.y -= 0x1000; \
    if (block.startHeading < 0) block.startHeading += 0x6487

// USA: func_020399b0
// JPN: func_02039408
extern "C" ARM void func_020399b0(GameObject* self, unsigned short field, const Vector3i* position, int heading) {
    self->obj3D_.SetField06(field);
    self->obj3D_.position_ = *position;
    SetVecYFromValue02033874(reinterpret_cast<Obj02033874*>(self), heading);
    *(short*)((char*)self + 0xb2) = 0;
    if (((signed char*)self)[0x1c9 - kActorTailDelta] > 0) ((unsigned char*)self)[0x1ce - kActorTailDelta] |= 4;
    ((signed char*)self)[0x1cb - kActorTailDelta] = -1;
    ((unsigned char*)self)[0x1cc - kActorTailDelta] = 0;
    unsigned char* settings = static_cast<unsigned char*>(GetField0x3f8Address(GameState::GetInstance()));
    Zone3D* zone = static_cast<Zone3D*>(func_02012fe4());
    ClearBytesAndZeroBlock02039d24(reinterpret_cast<unsigned char*>(self));
    if (settings[0x66]) {
        InitBlock02038508((SubBlock02038508*)((char*)self + 0x26c - kActorTailDelta));
        ((ActorActionFlags*)((char*)self + 0xe0))->active = 0;
        self->obj3D_.DisableFlag(0x1180);
        SetByte0xbeShiftPrev(reinterpret_cast<Bytes02033b88*>(self), 0);
        func_ov017_021d3f00((SubBlock02038508*)((char*)self + 0x26c - kActorTailDelta), 0, 1);
    }
    if (*reinterpret_cast<short*>(settings + 0x6c) < 0) {
        SetByte0xbeShiftPrev(reinterpret_cast<Bytes02033b88*>(self), 0);
        return;
    }
    if (*reinterpret_cast<short*>(settings + 0x6c) == 9999) {
        self->obj3D_.DisableFlag(0x1000);
        EnqueueEventTag60Field_021d440c(-1);
        func_ov017_021d3f00((SubBlock02038508*)((char*)self + 0x26c - kActorTailDelta), 0, 1);
        return;
    }
    SubBlock02038508 block;
    InitBlock02038508(&block);
    ZoneFeatures::Opcode6aEntry* node = FindNodeKind9ById(&zone->substruct_6c_, *reinterpret_cast<short*>(settings + 0x6c));
    if (!node) return;
    int cosine = fix32cos(node->unk_20);
    Vector3i direction;
    direction.x = fix32sin(node->unk_20);
    direction.y = 0;
    direction.z = cosine;
    Vector3fix_Normalize(&direction, &direction);
    ZoneFeatures::Opcode6aEntry* linked = FindNodeKind9ById(&zone->substruct_6c_, node->unk_2c.type9.unk_2);
    if (!linked) return;
    if (node->unk_2c.type9.unk_5 & 1) {
        SET_ACTION_POINTS(linked, node, 1);
    } else {
        SET_ACTION_POINTS(node, linked, 0);
    }
    block.command = 2;
    block.active = 1;
    block.heading = node->unk_20;
    CopyBlockTo0x26c(self, &block);
    int difference = block.end.vec.y - block.start.vec.y;
    int y = block.start.vec.y + FIX32_MULTIPLY(difference, *reinterpret_cast<short*>(settings + 0x6a));
    Vector3i adjusted;
    adjusted = self->obj3D_.position_;
    adjusted.y = y;
    self->obj3D_.position_ = adjusted;
    SetVecYFromValue02033874(reinterpret_cast<Obj02033874*>(self), node->unk_20);
    self->obj3D_.MaybeSetRegularAnimation(data_020efb4e, 0);
    self->obj3D_.EnableFlag(0x180);
    ((ActorActionFlags*)((char*)self + 0xe0))->active = 1;
    CancelPendingAction020397cc(reinterpret_cast<Obj020397cc*>(self), 1);
}
