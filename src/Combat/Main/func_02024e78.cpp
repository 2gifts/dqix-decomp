#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "System/Memory.h"
#include <globaldefs.h>

struct ForwardingEntry {
    int unknown0;
    int index;
    int parameter1;
    int parameter2;
};

struct CombatActionReceiverView {
    unsigned char unknown0[0x18];
    int tileX;
    int tileY;
    unsigned char unknown20[0xc];
    ForwardingEntry *forwardingEntries;
    int forwardingCount;
    unsigned char unknown34[4];
    fix32_t scale;
    unsigned char unknown3c[8];
    int originX;
    int originY;
    unsigned char unknown4c[0x510];
    unsigned char resetPending;
    unsigned char unknown55d[0x47];
    int flags;
    unsigned char unknown5a8[0x418];
    unsigned char actionState;
};

struct List_02027878;
struct Entry_02027878;
struct Bcb8Params;
struct BattleTimer0202441c;
struct Actor02024d48;

void *GetData02105254();
extern "C" void *func_02012fe4();
void SetArraySlotFlag0203b718(void *owner, int mode, int index, int value);
Entry_02027878 *GetEntryFromList(List_02027878 *list, int index);
void ForwardParamsToB8bc(Bcb8Params *params, int a, int b);
void AccumulateBattleTimer0202441c(BattleTimer0202441c *receiver);
int CheckCombatantReadyForAction020243b8(void *receiver, int combatantId);
int CheckActionAllowed(Actor02024d48 *entry, int state);
void SetElementFields0202756c(void *receiver, int x, int y, int index, unsigned char type, unsigned char flags,
                              unsigned short palette, unsigned char opacity, int scaleX, int scaleY);

// USA: func_02024e78
extern "C" ARM void func_02024e78(void *receiver) {
    CombatActionReceiverView *obj = static_cast<CombatActionReceiverView *>(receiver);
    GameObject *actor             = GameState::GetInstance()->GetUnknownGameObject();
    void *resourceData            = GetData02105254();
    func_02012fe4();
    Vector3i position = actor->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    int count     = func_020236dc(entries, groups, &position);
    fix32_t scale = obj->scale;
    int originX   = (int) ((float) FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    int originY   = (int) ((float) FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    obj->originX  = originX;
    obj->originY  = originY;

    if (obj->resetPending) {
        obj->resetPending = 0;
        SetArraySlotFlag0203b718(resourceData, 1, 0, 0);
        for (int i = 0; i < obj->forwardingCount; i++) {
            Entry_02027878 *entry = GetEntryFromList(static_cast<List_02027878 *>(receiver), obj->forwardingEntries[i].index);
            if (entry) {
                ForwardParamsToB8bc(reinterpret_cast<Bcb8Params *>((char *) entry + 8), obj->forwardingEntries[i].parameter1,
                                    obj->forwardingEntries[i].parameter2);
            }
        }
    }
    AccumulateBattleTimer0202441c(static_cast<BattleTimer0202441c *>(receiver));
    for (int i = 0; i < count; i++) {
        CombatActionPosition *entry = &entries[i];
        if (!CheckCombatantReadyForAction020243b8(receiver, entry->combatantId)) continue;
        fix32_t scale = obj->scale;
        int x         = (int) ((float) FIX32_MULTIPLY(entry->position.x, scale) / 4096.0f) - (obj->tileX << 3);
        int y         = (int) ((float) FIX32_MULTIPLY(entry->position.z, scale) / 4096.0f) - (obj->tileY << 3);
        if (entry->variant >= 0) {
            int group = groups[entry->group] - 1;
            x += data_020e70f0[group][entry->variant][0];
            y += data_020e70f4[group][entry->variant][0];
        }
        if (obj->flags & 1) {
            if (IsNonCombatantAction(entry->type)) continue;
        }
        if (!CheckActionAllowed(reinterpret_cast<Actor02024d48 *>(entry), obj->actionState)) continue;
        SetElementFields0202756c(receiver, (x - 4) << 12, (y - 4) << 12, entry->elementId, entry->type, 0, entry->palette,
                                 0xff, 0x1000, 0x1000);
    }
    func_02023b5c(receiver, obj->tileX << 3, obj->tileY << 3, -4, -4, 0);
    func_02023d84(receiver, entries, count, obj->tileX << 3, obj->tileY << 3, -4, -4, 0);
}
