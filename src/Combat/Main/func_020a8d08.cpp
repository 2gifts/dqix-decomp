#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct FlagWord020466f4;
struct Obj02033874;
struct Obj020397cc;

void* GetPtrField0x2a04(GameState* battleStruct);
int GetSignedByte0x1c8(void* obj);
void SetByteField0x253(void* obj);
void EnqueueEventTag35_021d2ad0(short a, int b, int c, int d, unsigned char e);
void EnqueueEventTag36_021d2c34(unsigned char a, unsigned char b, unsigned char c);
void* GetDataPtr02114e04_020d6c00();
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void SetVecYFromValue02033874(struct Obj02033874* obj, int value);
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

struct Combatant020a8d08 {
    Object3D obj;
    short height;
    short y;
    char pad_b0[0xc1 - 0xb0];
    unsigned char f_c1;
};

struct Obj020a8d08 {
    char pad0[4];
    unsigned char f4;
    unsigned char f5;
    char pad6[2];
    int offsetY;
    char padc[4];
    int offsetX;
    int offsetZ;
};

// USA: func_020a8d08
extern "C" ARM void func_020a8d08(struct Obj020a8d08* obj, unsigned char index) {
    GameState* state = GameState::GetInstance();
    Combatant020a8d08* actor = (Combatant020a8d08*)state->GetPartyMemberByIndex(index);
    Object3D* other = &state->GetUnknownGameObject()->obj3D_;
    GetPtrField0x2a04(state);
    state->GetPartyMemberByIndex(GetSignedByte0x1c8(actor));
    if ((obj->f4 & (1 << index)) == 0) {
        return;
    }
    if (obj->f5 & (1 << index)) {
        return;
    }
    Vector3i t;
    t = actor->obj.position_;
    t.x += obj->offsetX;
    t.z += obj->offsetZ;
    actor->obj.position_ = t;
    if (actor->height == 0) {
        actor->f_c1 &= ~8;
        SetByteField0x253(actor);
        obj->f5 |= (1 << index);
        if (actor->obj.unknown_4_ != other->unknown_4_) {
            actor->obj.position_ = other->position_;
        }
        Vector3i v = actor->obj.position_;
        EnqueueEventTag35_021d2ad0(index, v.x, v.y, v.z, 0);
        EnqueueEventTag36_021d2c34(index, 0x1f, 0);
        ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x402);
    } else {
        SetVecYFromValue02033874((struct Obj02033874*)actor, actor->y + obj->offsetY);
        if (actor->obj.unknown_4_ == other->unknown_4_) {
            obj->offsetY -= 40;
        }
        CancelPendingAction020397cc((struct Obj020397cc*)actor, 1);
    }
}
