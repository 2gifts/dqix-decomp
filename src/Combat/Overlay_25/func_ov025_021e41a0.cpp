#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct EffectCommand {
    unsigned char padding0[8];
    const char* name;
    unsigned char type;
    signed char slot;
    unsigned short id;
    unsigned char flags;
    unsigned char padding11;
    short x;
    short y;
    short z;
    short minimumFrame;
    unsigned char mode;
};
struct InitStruct02078484Struct {
    char name[0x10];
    unsigned char type;
    unsigned char screenSpace : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flags : 5;
    short field12;
    short combatant;
    short field16;
    short field18;
    short field1a;
    short field1c;
    short padding1e;
    Vector3i field20;
    Vector3i position;
    Vector3i rotation;
    Vector3i scale;
};
struct List02160094;
struct EffectSource { unsigned char padding0[0x20]; unsigned short id; };
struct EffectTarget { unsigned char padding0[0xe]; short id; };
struct List021600f8 { unsigned char padding0[9]; unsigned char count; };
#if defined(jpn)
struct EffectWork { unsigned char padding0[0x70f2]; unsigned short id; };
#else
struct EffectWork { unsigned char padding0[0x6f02]; unsigned short id; };
#endif
#if defined(jpn)
struct EffectGlobals { unsigned char padding0[4]; char* slots; };
#else
struct EffectGlobals { unsigned char padding0[0xc]; char* slots; };
#endif
extern EffectGlobals data_ov025_021ef988;
extern "C" void* func_02057924();
extern "C" EffectSource* _Z22GetNodeAtIndex02160094P12List02160094i(List02160094*, int);
extern "C" EffectTarget* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8*, int);
extern "C" void _Z18InitStruct02078484P24InitStruct02078484Struct(InitStruct02078484Struct*);
EffectWork* GetActiveCombatWork();
extern "C" void* _Z26FindNodeAndProcess02057fb4Pvii(void*, int, int);
extern "C" void** _Z28GetSlotPtr_021e8cf0_021e8cf0Pci(char*, int);

static inline void ScaleHorizontal(Vector3i* offset, int factor) {
    offset->x *= factor;
    offset->z *= factor;
}

// JPN: func_ov025_021e4690
// USA: func_ov025_021e41a0
extern "C" ARM int func_ov025_021e41a0(EffectCommand* command, List021600f8* list) {
    GameState* game = GameState::GetInstance();
    void* manager = func_02057924();
    EffectSource* source = _Z22GetNodeAtIndex02160094P12List02160094i((List02160094*)list, 0);
    if (!source) return 0;
    int sourceId = source->id;
    GameObject* object = game->GetGameObjectByIndex(sourceId);
    int frame = object->obj3D_.normalizedAnimationTime_;
    if (command->minimumFrame > 0 && frame < command->minimumFrame) return 0;
    InitStruct02078484Struct effect;
    _Z18InitStruct02078484P24InitStruct02078484Struct(&effect);
    effect.flag2 = 0;
    int attach = 1;
    if (command->flags & 1) {
        Vector3i position = {};
        for (int i = 0; i < list->count; i++) {
            EffectTarget* target = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, i);
            if (target) {
                GameObject* targetObject = game->GetGameObjectByIndex(target->id);
                if (targetObject) {
                    Vector3i targetPosition = targetObject->obj3D_.position_;
                    Vector3fix_Add(&position, &targetPosition, &position);
                    effect.scale = targetObject->obj3D_.GetScale();
                }
            }
        }
        if (list->count) {
            int scale = 4096.0f * (1.0f / (unsigned int)list->count);
            Vector3fixMultiplyScalar(&position, scale, &position);
        }
        EffectTarget* target = _Z22GetNodeAtIndex021600f8P12List021600f8i(list, 0);
        Vector3i offset = {command->x, command->y, command->z};
        int party = 0;
        int id = target->id;
        if (id >= 0 && id <= 3) party = 1;
        if (!party) ScaleHorizontal(&offset, -1);
        Vector3fix_Add(&position, &offset, &position);
        effect.position = position;
        int facingParty = 0;
        int facingId = target->id;
        if (facingId >= 0 && facingId <= 3) facingParty = 1;
        effect.rotation.y = facingParty ? 0x3244 : 0;
        attach = 0;
    }
    if (attach) effect.combatant = sourceId;
    if (command->name) strcpy(effect.name, command->name);
    effect.type = command->type;
    effect.screenSpace = command->mode;
    if (effect.screenSpace) {
        effect.combatant = -1;
        effect.scale.x = 0x800;
        effect.scale.y = 0x800;
        effect.scale.z = 0x800;
    }
    EffectWork* work = GetActiveCombatWork();
    work->id = command->id;
    void* instance = _Z26FindNodeAndProcess02057fb4Pvii(manager, command->id, (int)&effect);
    void** slot = _Z28GetSlotPtr_021e8cf0_021e8cf0Pci(data_ov025_021ef988.slots, command->slot);
    if (slot) *slot = instance;
    return 1;
}
