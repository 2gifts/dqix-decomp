#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "System/ColorEffects.h"
#include "System/Memory.h"
#include "std_library_functions.h"

struct Bcb8Params;
struct Entry_02027878 {
    char padding0[8];
    Bcb8Params* forwarding;
};
struct List_02027878;
struct BattleTimer0202441c;
struct Actor02024d48;
struct ForwardingRecord0202555c {
    int field_0x0;
    int entryIndex;
    int x;
    int y;
};
struct Slot0202555c {
    char data[0x28];
};
struct Receiver0202555c {
    char padding0[0x18];
    int forwardingX;
    int forwardingY;
    char padding20[0xc];
    ForwardingRecord0202555c* forwarding;
    int forwardingCount;
    char padding34[4];
    fix32_t scale;
    int tileX;
    int tileY;
    int screenX;
    int screenY;
    char padding4c[0x74 - 0x4c];
    int forwardingFill;
    char padding78[0x94 - 0x78];
    int bits94;
    char padding98[0xe8 - 0x98];
    Slot0202555c slots[1];
    char padding110[0x55c - 0x110];
    unsigned char forwardingPending;
    char padding55d[0x5b0 - 0x55d];
    fix32_t cameraHeight;
    char padding5b4[0x9c0 - 0x5b4];
    unsigned char actionState;
};
extern "C" void* _Z24GetData02105254_0203b628v();
extern "C" void* func_02012fe4();
extern "C" void _Z24SetArraySlotFlag0203b718Pviii(void*, int, int, int);
Entry_02027878* GetEntryFromList(List_02027878*, int);
extern "C" void _Z28ForwardParamsToB8bc_0203bcb8P10Bcb8Paramsii(Bcb8Params*, int, int);
extern "C" void _Z29AccumulateBattleTimer0202441cP19BattleTimer0202441c(BattleTimer0202441c*);
extern "C" int _Z36CheckCombatantReadyForAction020243b8Pvi(void*, int);
int CheckActionAllowed(Actor02024d48*, int);
extern "C" void _Z24SetElementFields0202756cPviiihhthii(void*, int, int, int, unsigned char, unsigned char, unsigned short, unsigned char, int, int);
extern "C" void _Z19SetBitfield0205afdciPvi(int, void*, int);

// USA: func_0202555c
extern "C" ARM void func_0202555c(Receiver0202555c* self) {
    char* slotData;
    GameObject* object;
    void* displayState;
    int count;
    int screenX;
    fix32_t oldHeight;
    int cameraY;
    int objectY;
    int below;
    int above;
    fix32_t product;
    int tileX;
    int tileY;
    int i;
    Entry_02027878* forwardEntry;
    int j;
    CombatActionPosition* entry;
    int x;
    int y;
    int group;
    int isSpecial;
    fix32_t scale;
    object = GameState::GetInstance()->GetUnknownGameObject();
    displayState = _Z24GetData02105254_0203b628v();
    func_02012fe4();
    Vector3i position = object->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    count = func_020236dc(entries, groups, &position);
    scale = self->scale;
    screenX = (int)((float)FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    oldHeight = self->cameraHeight;
    cameraY = (int)((float)FIX32_MULTIPLY(self->cameraHeight, scale) / 4096.0f);
    objectY = (int)((float)FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    below = cameraY - objectY;
    above = objectY - cameraY;
    if (above > 0x1e) {
        self->cameraHeight += fix32_Divide((above - 0x1e) << 12, scale);
    } else if (below > 0x37) {
        self->cameraHeight -= fix32_Divide((below - 0x37) << 12, scale);
    }
    product = FIX32_MULTIPLY(oldHeight, self->cameraHeight);
    if (product < 0) {
        self->cameraHeight = 0;
    }
    scale = self->scale;
    cameraY = (int)((float)FIX32_MULTIPLY(self->cameraHeight, scale) / 4096.0f);
    tileX = screenX < 0 ? screenX / 8 - 1 : screenX / 8;
    tileY = cameraY < 0 ? cameraY / 8 - 1 : cameraY / 8;
    if (self->forwardingY - tileY + 14 != 0 || cameraY % 8 != 0) {
        if (above > 0) {
            self->cameraHeight = fix32_Divide((objectY - 0x1e) << 12, scale);
        } else if (below > 0) {
            self->cameraHeight = fix32_Divide((objectY + 0x37) << 12, scale);
        }
    }
    cameraY = (int)((float)FIX32_MULTIPLY(self->cameraHeight, self->scale) / 4096.0f);
    tileY = cameraY < 0 ? cameraY / 8 - 1 : cameraY / 8;
    self->screenX = screenX;
    self->screenY = cameraY;
    if (self->tileY != tileY) {
        self->forwardingPending = 1;
    }
    self->tileX = tileX;
    self->tileY = tileY;
    if (self->forwardingPending) {
        self->forwardingPending = 0;
        _Z24SetArraySlotFlag0203b718Pviii(displayState, 1, 0, self->forwardingFill);
        for (i = 0; i < self->forwardingCount; ++i) {
            forwardEntry = GetEntryFromList((List_02027878*)self, self->forwarding[i].entryIndex);
            if (forwardEntry) {
                _Z28ForwardParamsToB8bc_0203bcb8P10Bcb8Paramsii((Bcb8Params*)((char*)forwardEntry + 8), self->forwarding[i].x,
                                    self->forwardingY + self->forwarding[i].y - tileY + 16);
            }
        }
    }
    _Z29AccumulateBattleTimer0202441cP19BattleTimer0202441c((BattleTimer0202441c*)self);
    for (j = 0; j < count; ++j) {
        entry = &entries[j];
        if (!_Z36CheckCombatantReadyForAction020243b8Pvi(self, entry->combatantId)) {
            continue;
        }
        scale = self->scale;
        x = (int)((float)FIX32_MULTIPLY(entry->position.x, scale) / 4096.0f) - (self->forwardingX << 3);
        y = (int)((float)FIX32_MULTIPLY(entry->position.z, scale) / 4096.0f) - self->screenY;
        if (entry->variant >= 0) {
            group = groups[entry->group] - 1;
            x += data_020e70f0[group][entry->variant][0];
            y += data_020e70f4[group][entry->variant][0];
        }
        isSpecial = entry->type == 0x74;
        if (isSpecial) {
            _Z24SetElementFields0202756cPviiihhthii(self, (x - 4) << 12, (y + 0x5c) << 12, entry->elementId, entry->type, 0,
                                     entry->palette, 0xff, 0x1000, 0x1000);
            continue;
        }
        if (!CheckActionAllowed((Actor02024d48*)entry, self->actionState)) {
            continue;
        }
        slotData = (char*)self->slots + (short)entry->elementId * (short)40;
        if (entry->flag13) {
            ColorEffect_ConfigureAlphaBlend(0x04001050, 0, 3, 8, 8);
            _Z19SetBitfield0205afdciPvi((int)&self->bits94, slotData, 1);
        } else {
            _Z19SetBitfield0205afdciPvi((int)&self->bits94, slotData, 0);
        }
        _Z24SetElementFields0202756cPviiihhthii(self, (x - 4) << 12, (y + 0x5c) << 12, entry->elementId, entry->type, 0,
                                 entry->palette, 0xff, 0x1000, 0x1000);
    }
    func_02023b5c(self, self->forwardingX << 3, self->screenY, -4, 0x5c, 0);
    func_02023d84(self, entries, count, self->forwardingX << 3, self->screenY, -4, 0x5c, 0);
}
