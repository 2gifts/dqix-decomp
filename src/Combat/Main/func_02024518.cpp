#include <globaldefs.h>
#include "Combat/ActionDisplay.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "System/Memory.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kActionStateOffset = 0x914, kVisitedIndex = 0x4c };
#define data_020e7074 data_020e7940
#define data_020e7076 data_020e7942
#define data_020e7056 data_020e7922
#define data_020e7057 data_020e7923
#else
enum { kActionStateOffset = 0x9c0, kVisitedIndex = 12 };
#endif

struct ForwardingRecord02024518 {
    int unknown0;
    int entryIndex;
    int x;
    int y;
};

struct MapReceiver02024518 {
    unsigned char unknown0[0x18];
    int forwardingX;
    int forwardingY;
    unsigned char unknown20[0xc];
    ForwardingRecord02024518 *forwarding;
    int forwardingCount;
    unsigned char unknown34[4];
    fix32_t scale;
    unsigned char unknown3c[8];
    int screenX;
    int screenY;
    unsigned char unknown4c[0x6c - 0x4c];
    int mapState;
    int mapPalette;
    int forwardingFill;
    unsigned char unknown78[0x55c - 0x78];
    unsigned char forwardingPending;
    unsigned char unknown55d[0x5a4 - 0x55d];
    int flags;
    unsigned char unknown5a8[4];
    fix32_t cameraX;
    fix32_t cameraZ;
    unsigned char unknown5b4[kActionStateOffset - 0x5b4];
    unsigned char actionState;
};

struct List_02027878;
struct Entry_02027878;
struct Bcb8Params;
struct BattleTimer0202441c;
struct Actor02024d48;

extern short data_020e7074[][2];
extern short data_020e7076[][2];
extern signed char data_020e7056[][2];
extern signed char data_020e7057[][2];

void *GetData02105254_0203b628();
extern "C" Zone3D *func_02012fe4();
int IsInRange0201b5b0(int id);
extern "C" void func_02027974(void *object, const unsigned char* adjacencyData, int state);
extern "C" void func_0203b8bc(void *data, int mode, int index, int x, int y, int state, int width, int height,
                              unsigned short palette);
void SetArraySlotFlag0203b718(void *owner, int mode, int index, int value);
Entry_02027878 *GetEntryFromList(List_02027878 *list, int index);
void ForwardParamsToB8bc_0203bcb8(Bcb8Params *params, int a, int b);
void AccumulateBattleTimer0202441c(BattleTimer0202441c *receiver);
int CheckCombatantReadyForAction020243b8(void *receiver, int combatantId);
int CheckActionAllowed(Actor02024d48 *entry, int state);
void SetElementFields0202756c(void *receiver, int x, int y, int index, unsigned char type, unsigned char flags,
                              unsigned short palette, unsigned char opacity, int scaleX, int scaleY);

// USA: func_02024518
// JPN: func_02023eec
extern "C" ARM void func_02024518(MapReceiver02024518 *self) {
    int pz;
    int px;
    GameState *gameState  = GameState::GetInstance();
    GameObject *object    = gameState->GetUnknownGameObject();
    void *displayState    = GetData02105254_0203b628();
    Zone3D *zone          = func_02012fe4();
    int count;
    int zoneId            = zone->currentZoneID_;
    Vector3i position     = object->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    count = func_020236dc(entries, groups, &position);

    fix32_t scale = self->scale;
    int cameraX   = (int) ((float) FIX32_MULTIPLY(self->cameraX, self->scale) / 4096.0f);
    int cameraZ   = (int) ((float) FIX32_MULTIPLY(self->cameraZ, scale) / 4096.0f);
    int objectX   = (int) ((float) FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    int objectZ   = (int) ((float) FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    if (objectX - cameraX > 30 || cameraX - objectX > 30) {
        if (objectX > cameraX) {
            self->cameraX += fix32_Divide((objectX - cameraX - 30) << 12, scale);
        } else {
            self->cameraX -= fix32_Divide((cameraX - objectX - 30) << 12, scale);
        }
    }
    if (objectZ - cameraZ > 10 || cameraZ - objectZ > 20) {
        if (objectZ > cameraZ) {
            self->cameraZ += fix32_Divide((objectZ - cameraZ - 10) << 12, self->scale);
        } else {
            self->cameraZ -= fix32_Divide((cameraZ - objectZ - 20) << 12, self->scale);
        }
    }
    scale         = self->scale;
    cameraX       = (int) ((float) FIX32_MULTIPLY(self->cameraX, scale) / 4096.0f);
    cameraZ       = (int) ((float) FIX32_MULTIPLY(self->cameraZ, scale) / 4096.0f);
    self->screenX = cameraX;
    self->screenY = cameraZ;
    int tileX     = cameraX < 0 ? cameraX / 8 - 1 : cameraX / 8;
    int tileZ     = cameraZ < 0 ? cameraZ / 8 - 1 : cameraZ / 8;

    int markX;
    int markZ;
    if (IsInRange0201b5b0(zoneId)) {
        if (self->mapState == 0) return;
        if (zone->unknown_424_ == 0) {
            unsigned char *visitedTiles =
                (unsigned char*)&gameState->unk_6fc0[kVisitedIndex] + ((zoneId % 20) - 1) * 32;
            fix32_t angle = fix32_Divide(FIX32_MULTIPLY(object->obj3D_.rotation_.y, 0xb4000), 0x3243);
            if (angle > 0xb4000) angle -= 0x168000;
            angle >>= 12;
            if (-157 > angle || angle > 157) {
                markX = (int) ((4.0f + (float) position.x / 4096.0f) / 8.0f);
                markZ = (int) (((float) position.z / 4096.0f - 2.0f) / 8.0f);
            } else {
                int found = 0;
                px        = position.x;
                pz        = position.z;
                for (int i = 0; i < 7 && !found; i++) {
                    if (data_020e7074[i][0] >= angle && angle > data_020e7076[i][0]) {
                        markX = (int) (((float) px / 4096.0f + (float) data_020e7056[i][0]) / 8.0f);
                        markZ = (int) (((float) pz / 4096.0f + (float) data_020e7057[i][0]) / 8.0f);
                        found = 1;
                    }
                }
            }
            if (markX < 8) {
                visitedTiles[markZ * 2] |= 1U << markX;
            } else {
                visitedTiles[markZ * 2 + 1] |= 1U << (markX - 8);
            }
            int centerX = (int) ((4.0f + (float) position.x / 4096.0f) / 8.0f);
            int centerZ = (int) ((4.0f + (float) position.z / 4096.0f) / 8.0f);
            if (centerX < 8) {
                visitedTiles[centerZ * 2] |= 1U << centerX;
            } else {
                visitedTiles[centerZ * 2 + 1] |= 1U << (centerX - 8);
            }
            ActiveGrottoClass* grotto = zone->GetActiveGrotto();
            func_02027974(self, grotto->floorMap_.pMapAdjacencyData, self->mapState);
        }
        self->forwardingPending = 0;
        SetArraySlotFlag0203b718(displayState, 1, 0, self->forwardingFill);
        int mapX        = self->forwardingX - tileX;
        int mapY        = self->forwardingY - tileZ + 16;
        void *mapLayer  = GetData02105254_0203b628();
        func_0203b8bc(mapLayer, 1, 0, mapX + 32, mapY, self->mapState, 32, 32, self->mapPalette);
    } else {
        self->forwardingPending = 0;
        SetArraySlotFlag0203b718(displayState, 1, 0, self->forwardingFill);
        for (int i = 0; i < self->forwardingCount; i++) {
            Entry_02027878 *entry = GetEntryFromList((List_02027878*)self, self->forwarding[i].entryIndex);
            if (entry) {
                ForwardParamsToB8bc_0203bcb8((Bcb8Params*)((char*)entry + 8),
                                    self->forwardingX + self->forwarding[i].x - tileX + 32,
                                    self->forwardingY + self->forwarding[i].y - tileZ + 16);
            }
        }
    }
    AccumulateBattleTimer0202441c((BattleTimer0202441c*)self);
    for (int i = 0; i < count; i++) {
        CombatActionPosition *entry = &entries[i];
        if (!CheckCombatantReadyForAction020243b8(self, entry->combatantId)) continue;
        fix32_t entryScale = self->scale;
        int x = (int) ((float) FIX32_MULTIPLY(entry->position.x, entryScale) / 4096.0f) - self->screenX;
        int z = (int) ((float) FIX32_MULTIPLY(entry->position.z, entryScale) / 4096.0f) - self->screenY;
        if (entry->variant >= 0) {
            int group = groups[entry->group] - 1;
            x += data_020e70f0[group][entry->variant][0];
            z += data_020e70f4[group][entry->variant][0];
        }
        if (self->flags & 1) {
            if (IsNonCombatantAction(entry->type)) continue;
        }
        if (!CheckActionAllowed((Actor02024d48*)entry, self->actionState)) continue;
        SetElementFields0202756c(self, (x + 0x7c) << 12, (z + 0x5c) << 12, entry->elementId, entry->type, 0,
                                 entry->palette, 0xff, 0x1000, 0x1000);
    }
    func_02023b5c(self, self->screenX, self->screenY, 0x7c, 0x5c, 0);
    func_02023d84(self, entries, count, self->screenX, self->screenY, 0x7c, 0x5c, 0);
}
