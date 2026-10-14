#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Event_020da31c {
    unsigned char padding[8];
    int objectIndex;
    unsigned char field_0xc;
    unsigned char flags, kind, ticks, activations, started;
};
struct InitStruct02078484Struct {
    char filename[16];
    unsigned char enabled, flags;
    short field_0x12, objectIndex, field_0x16, lifetime, field_0x1a, field_0x1c;
    short padding_0x1e;
    int field_0x20, field_0x24, field_0x28;
    Vector3i position, rotation, scale;
};
struct ActorView_020da31c {
    Object3D object;
    short field_0xac, direction, field_0xb0, timer;
};
struct MatrixTarget_020da31c {
    unsigned char padding[0xe8];
    Matrix4x3 matrix;
};
struct State0205a180 {
    unsigned int field_0x0;
    MatrixTarget_020da31c* output;
};
extern "C" void* func_02057924();
void InitStruct02078484(InitStruct02078484Struct*);
void FindNodeAndProcess02057fb4(void*, int, int);
void* GetInlineRecordByBattleId_02058658(void*, int);
void StoreZeroAndField0xb6ToOut(State0205a180*);
void DispatchIfField0xc4NonNeg_0205ebfc(void*, int, int);
extern char data_020f2884[], data_020f2887[], data_02108760[];

// USA: func_020da31c
extern "C" ARM void func_020da31c(Event_020da31c* event) {
    void* manager = func_02057924();
    GameState* game = GameState::GetInstance();
    if (!manager || !game) return;
    switch (event->kind) {
    case 1: {
        GameObject* actor = game->GetMaybeWanderingMonsterByIndex(event->objectIndex);
        if (!actor) return;
        if (!(event->flags & 8)) {
            InitStruct02078484Struct effect;
            event->flags |= 8;
            InitStruct02078484(&effect);
            int index = event->objectIndex;
            effect.objectIndex = index;
            effect.enabled = 0;
            sprintf(effect.filename, data_020f2884, data_020f2887);
            effect.position.x = 0;
            effect.position.y = 0;
            effect.position.z = 0;
            effect.scale.x = 0x1000;
            effect.scale.y = 0x1000;
            effect.scale.z = 0x1000;
            FindNodeAndProcess02057fb4(manager, 0x14, (int)&effect);
        }
        int timer = ((ActorView_020da31c*)actor)->timer;
        int distance = fix32SignedAngleDistance(actor->obj3D_.rotation_.y, ((ActorView_020da31c*)actor)->direction);
        if (timer > 0x3d || distance != 0) ++event->ticks;
        if (event->ticks < 3) return;
        event->ticks = 0;
        InitStruct02078484Struct effect;
        InitStruct02078484(&effect);
        effect.position = actor->obj3D_.position_;
        effect.rotation = actor->obj3D_.rotation_;
        effect.scale.x = 200;
        effect.scale.y = 200;
        effect.scale.z = 200;
        sprintf(effect.filename, data_020f2884, data_020f2887);
        effect.flags |= 0x40;
        FindNodeAndProcess02057fb4(manager, 0x15, (int)&effect);
        break;
    }
    case 2: {
        GameObject* actor = game->GetGameObjectByIndex(event->objectIndex);
        if (!actor) return;
        if (!(event->flags & 8)) {
            InitStruct02078484Struct effect;
            event->flags |= 8;
            InitStruct02078484(&effect);
            int index = event->objectIndex;
            effect.objectIndex = index;
            effect.enabled = 0;
            sprintf(effect.filename, data_020f2884, data_020f2887);
            effect.position.x = 0;
            effect.position.y = 0;
            effect.position.z = 0;
            effect.scale.x = 0x3000;
            effect.scale.y = 0x1000;
            effect.scale.z = 0x3000;
            FindNodeAndProcess02057fb4(manager, 0x14, (int)&effect);
        }
        if (++event->ticks < 7) return;
        event->ticks = 0;
        InitStruct02078484Struct effect;
        InitStruct02078484(&effect);
        effect.position = actor->obj3D_.position_;
        effect.rotation = actor->obj3D_.rotation_;
        effect.scale.x = 225;
        effect.scale.y = 225;
        effect.scale.z = 225;
        sprintf(effect.filename, data_020f2884, data_020f2887);
        FindNodeAndProcess02057fb4(manager, 0x15, (int)&effect);
        break;
    }
    case 3: {
        GameObject* actor = game->GetMaybeWanderingMonsterByIndex(event->objectIndex);
        if (!actor) return;
        InitStruct02078484Struct effect;
        State0205a180* record = (State0205a180*)GetInlineRecordByBattleId_02058658(manager, 0xd0);
        if (record && record->output) {
            MatrixTarget_020da31c* output = record->output;
            Matrix4x3 result, world, offset, rotation;
            Mat4x3_WriteIdentity(&result);
            Mat4x3_WriteIdentity(&world);
            Mat4x3_ApplyTranslation(&world, &world, actor->obj3D_.position_.x,
                actor->obj3D_.position_.y, actor->obj3D_.position_.z);
            Mat4x3_WriteIdentity(&offset);
            Mat4x3_ApplyTranslation(&offset, &offset, 0, 0x3000, 0x800);
            rotation = RotationMatrixY(((ActorView_020da31c*)actor)->direction);
            Mat4x3_Multiply(&offset, &rotation, &result);
            Mat4x3_Multiply(&result, &world, &result);
            output->matrix = result;
        }
        if (!(event->flags & 0x10)) {
            event->ticks = 0;
            event->activations = 0;
            return;
        }
        ++event->ticks;
        if (event->activations < 1 && (event->flags & 0x10)) {
            if (!event->started) {
                InitStruct02078484(&effect);
                effect.position = actor->obj3D_.position_;
                effect.rotation = actor->obj3D_.rotation_;
                effect.lifetime = 90;
                effect.scale.x = 0x199;
                effect.scale.y = 0x199;
                effect.scale.z = 0x199;
                sprintf(effect.filename, data_020f2884, data_020f2887);
                effect.flags |= 0xb8;
                FindNodeAndProcess02057fb4(manager, 0x16, (int)&effect);
                event->started = 1;
                DispatchIfField0xc4NonNeg_0205ebfc(data_02108760, 1, 0);
            } else {
                State0205a180* active = (State0205a180*)GetInlineRecordByBattleId_02058658(manager, 0xd0);
                if (active) {
                    StoreZeroAndField0xb6ToOut(active);
                    DispatchIfField0xc4NonNeg_0205ebfc(data_02108760, 1, 0);
                }
            }
            ++event->activations;
        } else if (event->ticks >= 85) {
            event->flags &= ~0x10;
        }
        break;
    }
    }
}
