#include <globaldefs.h>

#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "System/Memory.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kActionStateOffset = 0x914 };
#else
enum { kActionStateOffset = 0x9c0 };
#endif

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
    unsigned char unknown5a8[kActionStateOffset - 0x5a8];
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

struct ForwardingRecordView {
    int unknown0;
    int entryIndex;
    int x;
    int z;
};

struct CombatProjectionReceiverView {
    unsigned char unknown0[0x18];
    int xOrigin;
    int forwardingOrigin;
    unsigned char unknown20[0xc];
    ForwardingRecordView *forwarding;
    int forwardingCount;
    unsigned char unknown34[4];
    fix32_t scale;
    int tileX;
    int tileZ;
    int screenX;
    int screenZ;
    unsigned char unknown4c[0x74 - 0x4c];
    int forwardingFill;
    unsigned char unknown78[0x55c - 0x78];
    unsigned char forwardingPending;
    unsigned char unknown55d[0x5a4 - 0x55d];
    int flags5a4;
    unsigned char unknown5a8[kActionStateOffset - 0x5a8];
    unsigned char actionFlag;
};

// USA: func_020251bc
extern "C" ARM void func_020251bc(void *receiver) {
    CombatProjectionReceiverView *state = static_cast<CombatProjectionReceiverView *>(receiver);
    GameObject *object                  = GameState::GetInstance()->GetUnknownGameObject();
    void *displayState                  = GetData02105254();
    func_02012fe4();
    Vector3fix position = object->obj3D_.position_;
    CombatActionPosition records[17];
    unsigned char groupCounts[32];
    memset(groupCounts, 0, sizeof(groupCounts));
    int count = func_020236dc(records, groupCounts, &position);

    fix32_t scale  = state->scale;
    int screenX    = (int) ((float) FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    int screenZ    = (int) ((float) FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    state->screenX = screenX;
    int tileX      = screenX < 0 ? screenX / 8 - 1 : screenX / 8;
    state->screenZ = screenZ;
    int tileZ      = screenZ < 0 ? screenZ / 8 - 1 : screenZ / 8;
    if (state->tileZ != tileZ) state->forwardingPending = 1;
    state->tileX = tileX;
    state->tileZ = tileZ;

    if (state->forwardingPending) {
        state->forwardingPending = 0;
        SetArraySlotFlag0203b718(displayState, 1, 0, state->forwardingFill);
        for (int i = 0; i < state->forwardingCount; i++) {
            Entry_02027878 *entry =
                GetEntryFromList(reinterpret_cast<List_02027878 *>(receiver), state->forwarding[i].entryIndex);
            if (entry) {
                ForwardParamsToB8bc(reinterpret_cast<Bcb8Params *>(reinterpret_cast<unsigned char *>(entry) + 8),
                                    state->forwarding[i].x, state->forwardingOrigin + state->forwarding[i].z - tileZ + 16);
            }
        }
    }
    AccumulateBattleTimer0202441c(reinterpret_cast<BattleTimer0202441c *>(receiver));
    for (int i = 0; i < count; i++) {
        CombatActionPosition *record = &records[i];
        if (!CheckCombatantReadyForAction020243b8(receiver, record->combatantId)) continue;
        fix32_t recordScale = state->scale;
        int x               = (int) ((float) FIX32_MULTIPLY(record->position.x, recordScale) / 4096.0f) - state->xOrigin * 8;
        int z               = (int) ((float) FIX32_MULTIPLY(record->position.z, recordScale) / 4096.0f) - state->screenZ;
        if (record->variant >= 0) {
            int group = groupCounts[record->group] - 1;
            x += data_020e70f0[group][record->variant][0];
            z += data_020e70f4[group][record->variant][0];
        }
        if (state->flags5a4 & 1) {
            if (IsNonCombatantAction(record->type)) continue;
        }
        if (!CheckActionAllowed(reinterpret_cast<Actor02024d48 *>(record), state->actionFlag)) continue;
        SetElementFields0202756c(receiver, (x - 4) * 0x1000, (z + 0x5c) * 0x1000, record->elementId, record->type, 0,
                                 record->palette, 0xff, 0x1000, 0x1000);
    }
    func_02023b5c(receiver, state->xOrigin * 8, state->screenZ, -4, 0x5c, 0);
    func_02023d84(receiver, records, count, state->xOrigin * 8, state->screenZ, -4, 0x5c, 0);
}
