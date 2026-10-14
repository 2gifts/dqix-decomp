#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "System/Memory.h"
#include "std_library_functions.h"

struct Bcb8Params;
struct Entry_02027878;
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
};
void* GetData02105254_0203b628();
extern "C" void* func_02012fe4();
void SetArraySlotFlag0203b718(void*, int, int, int);
Entry_02027878* GetEntryFromList(List_02027878*, int);
void ForwardParamsToB8bc_0203bcb8(Bcb8Params*, int, int);
void AccumulateBattleTimer0202441c(BattleTimer0202441c*);
int CheckCombatantReadyForAction020243b8(void*, int);
int CheckActionAllowed(Actor02024d48*, int);
void SetElementFields0202756c(void*, int, int, int, unsigned char, unsigned char, unsigned short, unsigned char, int, int);

#if defined(jpn)
enum { actionStateOffset = 0x914 };
#else
enum { actionStateOffset = 0x9c0 };
#endif

// USA: func_02025b0c
extern "C" ARM void func_02025b0c(Receiver02025b0c* self) {
    unsigned char* receiver = reinterpret_cast<unsigned char*>(self);
    GameObject* object = GameState::GetInstance()->GetUnknownGameObject();
    void* displayState = GetData02105254_0203b628();
    func_02012fe4();
    Vector3i position = object->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    int count = func_020236dc(entries, groups, &position);
    fix32_t& cameraHeight = *reinterpret_cast<fix32_t*>(receiver + 0x5b0);
    int screenX;
    int cameraY;
    fix32_t scale;
    scale = self->scale;
    screenX = (int)((float)FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    cameraY = (int)((float)FIX32_MULTIPLY(cameraHeight, scale) / 4096.0f);
    int objectY = (int)((float)FIX32_MULTIPLY(position.y, scale) / 4096.0f);
    if (cameraY - objectY > 5 || objectY - cameraY > 5) {
        if (objectY < cameraY) {
            cameraHeight -= fix32_Divide((cameraY - objectY - 5) << 12, scale);
        } else {
            cameraHeight += fix32_Divide((objectY - cameraY - 5) << 12, scale);
        }
    }
    cameraY = (int)((float)FIX32_MULTIPLY(cameraHeight, self->scale) / 4096.0f);
    self->screenX = screenX;
    self->screenY = cameraY;
    int tileY = cameraY < 0 ? cameraY / 8 - 1 : cameraY / 8;
    receiver[0x55c] = 0;
    SetArraySlotFlag0203b718(displayState, 1, 0, self->forwardingFill);
    for (int i = 0; i < self->forwardingCount; ++i) {
        Entry_02027878* entry = GetEntryFromList((List_02027878*)self, self->forwarding[i].entryIndex);
        if (entry) {
            int forwardY = self->forwardingY + self->forwarding[i].y;
            int forwardX = self->forwardingX + self->forwarding[i].x;
            ForwardParamsToB8bc_0203bcb8(reinterpret_cast<Bcb8Params*>(reinterpret_cast<unsigned char*>(entry) + 8), forwardX + 16, tileY + forwardY + 16);
        }
    }
    AccumulateBattleTimer0202441c((BattleTimer0202441c*)self);
    for (int i = 0; i < count; ++i) {
        CombatActionPosition* entry = &entries[i];
        if (!CheckCombatantReadyForAction020243b8(self, entry->combatantId)) {
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
        if (*reinterpret_cast<int*>(receiver + 0x5a4) & 1) {
            if (IsNonCombatantAction(entry->type)) {
                continue;
            }
        }
        if (!CheckActionAllowed((Actor02024d48*)entry, receiver[actionStateOffset])) {
            continue;
        }
        SetElementFields0202756c(self, (x + 0x7c) << 12, (y + 0x5c) << 12,
            entry->elementId, entry->type, 0, entry->palette, 0xff, 0x1000, 0x1000);
    }
    func_02023b5c(self, 0, self->screenY, 0x7c, 0x5c, 1);
    func_02023d84(self, entries, count, 0, self->screenY, 0x7c, 0x5c, 1);
}
