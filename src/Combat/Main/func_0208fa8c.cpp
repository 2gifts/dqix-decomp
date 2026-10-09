#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/DetailedTreasureMapData.h"

struct ZoneState { unsigned short zoneId; };
struct DetailedMapFlags { char pad0[0x260]; unsigned char field260; };
GameResources* func_ov017_0218b5b0();
void* GetField0x3f8Address(GameState*);
extern "C" int _Z17IsInRange0201b588i(int);
extern "C" void _Z31ClearOrFillBattleRegion02027ad8ii(int, int);
int CheckField0NonZero(int*);
extern "C" {
int* func_0202ae18();
ZoneState* func_02012fe4();
void func_020a0cc4(int);
void func_020a3720();
void func_020a395c();
void func_020a0c0c();
int func_0202c540(int*);
}
void ExportDetailedTreasureMapData(const TreasureMapMetadata*, DetailedTreasureMapData*, bool, const unsigned char*);

// USA: func_0208fa8c
extern "C" ARM void func_0208fa8c(DetailedTreasureMapData* map) {
    ZoneState* current;
    GameState* game = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    int* session = func_0202ae18();
    current = (ZoneState*)GetField0x3f8Address(game);
    GrottoStruct* grotto = game->GetGrottoStruct();
    int currentZone;
    void* region = resources->unknown_ptr_36d0;
    ZoneState* destination = func_02012fe4();
    currentZone = current->zoneId;
    int nextZone = destination->zoneId;
    if (_Z17IsInRange0201b588i(currentZone) && !_Z17IsInRange0201b588i(nextZone) &&
        (nextZone < 30000 || nextZone > 39999)) {
        map->Clear();
        func_020a0cc4(0x2000);
        func_020a3720();
        ExportDetailedTreasureMapData(&grotto->activeMapData, map, true, 0);
        func_020a395c();
        func_020a0c0c();
        if (!grotto->unknown_0[0]) ((DetailedMapFlags*)map)->field260 = 1;
        grotto->unknown_0[1] = 0;
        if (func_0202c540(session)) grotto->activeMapLevel = map->GetLevel();
        if (region && nextZone) _Z31ClearOrFillBattleRegion02027ad8ii((int)region, map->discoveryState_ == 3);
    } else if (!_Z17IsInRange0201b588i(currentZone) && _Z17IsInRange0201b588i(nextZone) &&
               (currentZone < 30000 || currentZone > 39999)) {
        if (CheckField0NonZero(session) && func_0202c540(session) && !grotto->unknown_0[1])
            grotto->unknown_0[1] = 0;
        else grotto->unknown_0[1] = 1;
        if (region) _Z31ClearOrFillBattleRegion02027ad8ii((int)region, 0);
    }
}
