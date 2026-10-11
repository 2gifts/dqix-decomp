#include <globaldefs.h>
#include "World/Object3D.h"
#include "Memory/SafeAllocator.h"

struct Struct205563c {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
};
struct EffectObject020d6f9c { unsigned char pad0[0xe8]; Matrix4x3 matrix; };
struct Obj02055660 { void* field0; void* field4; int field8; int fieldc; };

extern "C" void _Z18InitStruct02059cc8Ph(unsigned char* obj);
void ClearSevenWords(Struct205563c* obj);
extern "C" int _Z17MaybeInit02055660P11Obj02055660iii(Obj02055660* obj, int data, int model, int allocator);
extern const Vector3fix data_020ee20c;
extern const Vector3fix data_020ee200;

struct ReactionFlags020d6f9c {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

struct ReactionConfig020d6f9c {
    char animationName[16];
    unsigned char animationFlags;
    ReactionFlags020d6f9c flags;
    short delay;
    short targetId;
    short field16;
    short duration;
    short field1a;
    short field1c;
    Vector3fix velocity;
    Vector3fix position;
    Vector3fix rotation;
    Vector3fix scale;

};

union ReactionPayload020d6f9c {
    Object3D object;
    Struct205563c clearHeader;
    Obj02055660 effect;
};

struct ReactionSlot020d6f9c {
    ReactionPayload020d6f9c payload;
    int type;
    short delay;
    short fieldb2;
    short fieldb4;
    short duration;
    int fieldb8;
    int fieldbc;
    Vector3fix velocity;
    ReactionFlags020d6f9c flags;
    unsigned char padcd[3];
    int reason;
    int active;
};

struct ReactionNode020d6f9c {
    int reason;
    unsigned char pad4[0x10];
    Object3D model;
    unsigned char effectData[0x128];
    int type;
    ReactionNode020d6f9c* next;
};

struct ReactionManager020d6f9c {
    ReactionSlot020d6f9c slots[12];
    ReactionNode020d6f9c* head;
    unsigned short mask;
    unsigned short pendingMask;
    SafeAllocator allocator;
};

// USA: func_020d6f9c
extern "C" ARM void func_020d6f9c(void* param0, int combatantId, int reason) {
    ReactionNode020d6f9c* node;
    ReactionManager020d6f9c* manager = (ReactionManager020d6f9c*)param0;
    if (manager->allocator.GetMaxPossibleAllocation() < 0x7e4) return;
    if (combatantId >= 0xc0) combatantId -= 0xbc;
    if (manager->mask & (1 << combatantId)) {
        if (manager->slots[combatantId].reason == reason) return;
        _Z18InitStruct02059cc8Ph((unsigned char*)&manager->slots[combatantId]);
        manager->slots[combatantId].active = 0;
    }
    ReactionConfig020d6f9c config;
    config.animationName[0] = 0;
    config.animationFlags = 1;
    config.delay = 0;
    config.targetId = -1;
    config.field16 = -1;
    config.duration = -1;
    config.field1a = -1;
    config.field1c = -0x1000;
    config.velocity.x = 0;
    config.velocity.y = 0;
    config.velocity.z = 0;
    config.position.x = 0;
    config.position.y = 0;
    config.position.z = 0;
    config.rotation.x = 0;
    config.rotation.y = 0;
    config.rotation.z = 0;
    config.scale.x = 0x1000;
    config.scale.y = 0x1000;
    config.scale.z = 0x1000;
    config.flags.bit0 = 0;
    config.flags.bit1 = 0;
    config.flags.bit2 = 1;
    config.flags.bit3 = 0;
    config.flags.bit4 = 0;
    config.flags.bit5 = 0;
    config.flags.bit6 = 0;
    config.flags.bit7 = 0;
    config.animationFlags = 0;
    Vector3fix defaultScale = data_020ee20c;
    config.scale = defaultScale;
    manager->mask |= 1 << combatantId;
    manager->pendingMask |= 1 << combatantId;
    node = manager->head;
    while (node != NULL) {
        if (reason == node->reason) break;
        node = node->next;
    }
    if (node == NULL) return;
    if (node->type == 0) {
        ReactionSlot020d6f9c* slot = &manager->slots[combatantId];
        slot->payload.object.Initialize();
        slot->payload.object.SetFlag16();
        slot->reason = node->reason;
        slot->type = node->type;
        node->model.ShallowCloneTo(&slot->payload.object);
        slot->payload.object.position_ = config.position;
        slot->payload.object.SetScale(&config.scale);
        int rotationY = config.rotation.y;
        int rotationX = config.rotation.x;
        slot->payload.object.rotation_.x = rotationX;
        slot->payload.object.rotation_.y = rotationY;
        slot->payload.object.rotation_.z = 0x3244;
        if (config.animationName[0] == 0) {
            slot->payload.object.MaybeSetBCFGAnimation(0, config.animationFlags);
        } else {
            slot->payload.object.MaybeSetRegularAnimation(config.animationName, config.animationFlags);
        }
        slot->delay = config.delay;
        slot->fieldb2 = config.targetId;
        slot->fieldb4 = config.field16;
        slot->duration = config.duration;
        slot->fieldb8 = config.field1a;
        slot->fieldbc = config.field1c;
        slot->velocity = config.velocity;
        slot->flags.bit1 = config.flags.bit0 != 0;
    } else {
        manager->slots[combatantId].reason = node->reason;
        manager->slots[combatantId].type = node->type;
        manager->slots[combatantId].delay = config.delay;
        manager->slots[combatantId].fieldb2 = config.targetId;
        manager->slots[combatantId].fieldb4 = config.field16;
        manager->slots[combatantId].duration = config.duration;
        manager->slots[combatantId].fieldb8 = config.field1a;
        manager->slots[combatantId].fieldbc = config.field1c;
        manager->slots[combatantId].velocity = config.velocity;
        manager->slots[combatantId].flags.bit1 = config.flags.bit0 != 0;
        ClearSevenWords(&manager->slots[combatantId].payload.clearHeader);
        _Z17MaybeInit02055660P11Obj02055660iii(&manager->slots[combatantId].payload.effect, (int)&node->effectData, (int)&node->model, (int)&manager->allocator);
        Matrix4x3 matrix;
        Mat4x3_WriteIdentity(&matrix);
        Mat4x3_ApplyTranslation(&matrix, &matrix, config.position.x, config.position.y, config.position.z);
        EffectObject020d6f9c* effect = (EffectObject020d6f9c*)manager->slots[combatantId].payload.effect.field4;
        effect->matrix = matrix;
        Vector3fix scale = data_020ee200;
        node->model.SetScale(&scale);
    }
}
