#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/NSBXX/Animation.h"

struct Struct205563c { int words[7]; };
struct EffectObject02057fd8 {
    unsigned char padding_0x0[8];
    int duration;
    unsigned char enabled;
    unsigned char padding_0xd[0x2c];
    unsigned char flag_0x39, flag_0x3a, flag_0x3b;
    unsigned char padding_0x3c[0xac];
    Matrix4x3 matrix;
};
struct Obj02055660 { void* field0; EffectObject02057fd8* effect; int field8, fieldc; };
struct ReactionFlags02057fd8 {
    unsigned char bit0 : 1, bit1 : 1, bit2 : 1, bit3 : 1;
    unsigned char bit4 : 1, bit5 : 1, bit6 : 1, bit7 : 1;
};
struct ReactionConfig02057fd8 {
    char animationName[16];
    unsigned char animationFlags;
    ReactionFlags02057fd8 flags;
    short delay, targetId, field16, duration, field1a, field1c;
    short padding_0x1e;
    Vector3i velocity, position, rotation, scale;
};
union ReactionPayload02057fd8 { Object3D object; Struct205563c header; Obj02055660 effect; };
struct ReactionSlot02057fd8 {
    ReactionPayload02057fd8 payload;
    int type;
    short delay, targetId, field16, duration;
    int field1a, field1c;
    Vector3i velocity;
    ReactionFlags02057fd8 flags;
    unsigned char padding_0xcd[3];
    int reason;
};
struct ReactionNode02057fd8 {
    int reason, allocator;
    unsigned char padding_0x8[0xc];
    Object3D model;
    unsigned char effectData[0x128];
    int type;
};
struct ReactionManager02057fd8 { unsigned char padding_0x0[8]; ReactionSlot02057fd8 slots[16]; };
void ClearSevenWords(Struct205563c*);
extern "C" int _Z17MaybeInit02055660P11Obj02055660iii(Obj02055660*, int, int, int);
void RegisterCombatantSlot(GameState*, int, GameObject*);
ModelRenderContext* GetModel3DContext(Model3D*);
extern "C" void _Z25CallHandlerFlag1_020e2fdcP20RenderCommandHandler(RenderCommandHandler*);
extern const char data_020e7d90[];
extern const Vector3i data_020e7d84;

#define COPY_REACTION_FLAGS_02057FD8() \
    manager->slots[index].flags.bit1 = config->flags.bit0 != 0; \
    manager->slots[index].flags.bit2 = config->flags.bit2 != 0; \
    manager->slots[index].flags.bit3 = config->flags.bit1 != 0; \
    manager->slots[index].flags.bit4 = config->flags.bit6 != 0; \
    manager->slots[index].flags.bit5 = config->flags.bit7 != 0

// USA: func_02057fd8
extern "C" ARM int func_02057fd8(ReactionManager02057fd8* manager, ReactionNode02057fd8* node, ReactionConfig02057fd8* config) {
    GameState* game = GameState::GetInstance();
    if (!node) return -1;
    if (!config) return -1;
    int id = -1;
    int index;
    for (index = 0; index < 16; ++index) {
        if (!game->GetGameObjectByIndex(index + 0xd0)) {
            id = index + 0xd0;
            break;
        }
    }
    if (id == -1) return -1;
    manager->slots[index].type = node->type;
    if (node->type == 0) {
        Object3D* object = &manager->slots[index].payload.object;
        object->Initialize();
        manager->slots[index].reason = node->reason;
        node->model.ShallowCloneTo(object);
        object->position_ = config->position;
        object->rotation_ = config->rotation;
        object->SetScale(config->scale.x, config->scale.y, config->scale.z);
        if (config->animationName[0] == 0) object->MaybeSetBCFGAnimation(0, config->animationFlags);
        else object->MaybeSetRegularAnimation(config->animationName, config->animationFlags);
        manager->slots[index].delay = config->delay;
        manager->slots[index].targetId = config->targetId;
        manager->slots[index].field16 = config->field16;
        manager->slots[index].duration = config->duration;
        manager->slots[index].field1a = config->field1a;
        manager->slots[index].field1c = config->field1c;
        manager->slots[index].velocity = config->velocity;
        COPY_REACTION_FLAGS_02057FD8();
        RegisterCombatantSlot(game, id, reinterpret_cast<GameObject*>(object));
        if (object->pModel_) {
            ModelRenderContext* context = GetModel3DContext(object->pModel_);
            NSBXXNameList* names = context->internalModel_ ? &context->internalModel_->boneList_ : 0;
            int bone = names ? NSBXXNameList_SearchIndex(names, data_020e7d90) : -1;
            if (bone >= 0) {
                SetModelRenderContextRenderCommandHook(context, _Z25CallHandlerFlag1_020e2fdcP20RenderCommandHandler, 0, 7, 1);
            }
        }
    } else {
        manager->slots[index].reason = node->reason;
        manager->slots[index].delay = config->delay;
        manager->slots[index].targetId = config->targetId;
        manager->slots[index].field16 = config->field16;
        manager->slots[index].duration = config->duration;
        manager->slots[index].field1a = config->field1a;
        manager->slots[index].field1c = config->field1c;
        manager->slots[index].velocity = config->velocity;
        COPY_REACTION_FLAGS_02057FD8();
        RegisterCombatantSlot(game, id, reinterpret_cast<GameObject*>(&node->model));
        ClearSevenWords(&manager->slots[index].payload.header);
        _Z17MaybeInit02055660P11Obj02055660iii(&manager->slots[index].payload.effect, reinterpret_cast<int>(node->effectData), reinterpret_cast<int>(&node->model), node->allocator);
        Matrix4x3 matrix __attribute__((aligned(4)));
        Mat4x3_WriteIdentity(&matrix);
        Mat4x3_ApplyTranslation(&matrix, &matrix, config->position.x, config->position.y, config->position.z);
        EffectObject02057fd8* effect = manager->slots[index].payload.effect.effect;
        effect->matrix = matrix;
        Vector3i scale = data_020e7d84;
        node->model.SetScale(&scale);
        if (config->flags.bit3 && manager->slots[index].payload.effect.effect) manager->slots[index].payload.effect.effect->enabled = 0;
        if (config->flags.bit4 && manager->slots[index].payload.effect.effect) manager->slots[index].payload.effect.effect->duration = config->duration;
        if (config->flags.bit5 && manager->slots[index].payload.effect.effect) manager->slots[index].payload.effect.effect->flag_0x39 = 1;
        if (config->flags.bit6 && manager->slots[index].payload.effect.effect) manager->slots[index].payload.effect.effect->flag_0x3a = 1;
        if (config->flags.bit7 && manager->slots[index].payload.effect.effect) manager->slots[index].payload.effect.effect->flag_0x3b = 1;
    }
    return id;
}
