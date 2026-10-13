#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "System/Memory.h"
#include "std_library_functions.h"

struct Bcb8Params {
    unsigned char field_0x0;
    unsigned char field_0x1;
    unsigned char padding2[6];
    unsigned int field_0x8;
    unsigned char paddingc[8];
    unsigned short field_0x14;
    unsigned short field_0x16;
    unsigned short field_0x18;
};
struct Entry_02027878 {
    char padding0[8];
    Bcb8Params forwarding;
};
struct List_02027878;
struct BattleTimer0202441c;
struct Actor02024d48;
struct ForwardingRecord02025b0c {
    int field_0x0;
    int entryIndex;
    int x;
    int y;
};
struct Receiver02025b0c {
    char padding0[0x18];
    int forwardingX;
    int forwardingY;
    char padding20[0xc];
    ForwardingRecord02025b0c* forwarding;
    int forwardingCount;
    char padding34[4];
    fix32_t scale;
    char padding3c[8];
    int screenX;
    int screenY;
    char padding4c[0x74 - 0x4c];
    int forwardingFill;
    char padding78[0x55c - 0x78];
    unsigned char forwardingPending;
    char padding55d[0x5a4 - 0x55d];
    int flags;
    char padding5a8[8];
    fix32_t cameraHeight;
    char padding5b4[0x9c0 - 0x5b4];
    unsigned char actionState;
};
void* GetData02105254();
extern "C" void* func_02012fe4();
extern "C" void _Z24SetArraySlotFlag0203b718Pviii(void*, int, int, int);
Entry_02027878* GetEntryFromList(List_02027878*, int);
void ForwardParamsToB8bc(Bcb8Params*, int, int);
extern "C" void _Z29AccumulateBattleTimer0202441cP19BattleTimer0202441c(BattleTimer0202441c*);
extern "C" int _Z36CheckCombatantReadyForAction020243b8Pvi(void*, int);
int CheckActionAllowed(Actor02024d48*, int);
extern "C" void _Z24SetElementFields0202756cPviiihhthii(void*, int, int, int, unsigned char, unsigned char, unsigned short, unsigned char, int, int);

// USA: func_02025b0c
extern "C" ARM void func_02025b0c(Receiver02025b0c* self) {
    GameObject* object = GameState::GetInstance()->GetUnknownGameObject();
    void* displayState = GetData02105254();
    func_02012fe4();
    Vector3i position = object->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    int count = func_020236dc(entries, groups, &position);
    int screenX;
    int cameraY;
    fix32_t scale;
    scale = self->scale;
    screenX = (int)((float)FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    cameraY = (int)((float)FIX32_MULTIPLY(self->cameraHeight, scale) / 4096.0f);
    int objectY = (int)((float)FIX32_MULTIPLY(position.y, scale) / 4096.0f);
    if (cameraY - objectY > 5 || objectY - cameraY > 5) {
        if (objectY < cameraY) {
            self->cameraHeight -= fix32_Divide((cameraY - objectY - 5) << 12, scale);
        } else {
            self->cameraHeight += fix32_Divide((objectY - cameraY - 5) << 12, scale);
        }
    }
    cameraY = (int)((float)FIX32_MULTIPLY(self->cameraHeight, self->scale) / 4096.0f);
    self->screenX = screenX;
    self->screenY = cameraY;
    int tileY = cameraY < 0 ? cameraY / 8 - 1 : cameraY / 8;
    self->forwardingPending = 0;
    _Z24SetArraySlotFlag0203b718Pviii(displayState, 1, 0, self->forwardingFill);
    for (int i = 0; i < self->forwardingCount; ++i) {
        Entry_02027878* entry = GetEntryFromList((List_02027878*)self, self->forwarding[i].entryIndex);
        if (entry) {
            int forwardY = self->forwardingY + self->forwarding[i].y;
            int forwardX = self->forwardingX + self->forwarding[i].x;
            ForwardParamsToB8bc(&entry->forwarding, forwardX + 16, tileY + forwardY + 16);
        }
    }
    _Z29AccumulateBattleTimer0202441cP19BattleTimer0202441c((BattleTimer0202441c*)self);
    for (int i = 0; i < count; ++i) {
        CombatActionPosition* entry = &entries[i];
        if (!_Z36CheckCombatantReadyForAction020243b8Pvi(self, entry->combatantId)) {
            continue;
        }
        fix32_t entryScale = self->scale;
        int x = (int)((float)FIX32_MULTIPLY(entry->position.x, entryScale) / 4096.0f);
        int y = -((int)((float)FIX32_MULTIPLY(entry->position.y, entryScale) / 4096.0f) - self->screenY);
        if (entry->variant >= 0) {
            int group = groups[entry->group] - 1;
            x += data_020e70f0[group][entry->variant][0];
            y -= data_020e70f4[group][entry->variant][0];
        }
        if (self->flags & 1) {
            if (IsNonCombatantAction(entry->type)) {
                continue;
            }
        }
        if (!CheckActionAllowed((Actor02024d48*)entry, self->actionState)) {
            continue;
        }
        _Z24SetElementFields0202756cPviiihhthii(self, (x + 0x7c) << 12, (y + 0x5c) << 12,
            entry->elementId, entry->type, 0, entry->palette, 0xff, 0x1000, 0x1000);
    }
    func_02023b5c(self, 0, self->screenY, 0x7c, 0x5c, 1);
    func_02023d84(self, entries, count, 0, self->screenY, 0x7c, 0x5c, 1);
}
