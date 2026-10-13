#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "std_library_functions.h"

struct Payload0201165c {
    int entranceX;
    int entranceY;
    int entranceZ;
    unsigned char environment;
    char pad1[3];
    unsigned char monsterRank;
};
extern "C" void _Z28InitTreasureMapEntry0201165cPcPKvi15Payload0201165c(char*, const void*, int, Payload0201165c);
extern "C" void func_020a3720();
extern "C" void func_020a395c();
struct SavedMapList020a9c14 {
    unsigned char mapCount;
    unsigned char flags;
    TreasureMapMetadata maps[99];
};
struct GameMapBank020a9c14 {
    unsigned char prefix[0x6400];
    SavedMapList020a9c14 mapList;
};
struct GameMapList020a9c14 {
    unsigned char prefix[0xf4];
    GameMapBank020a9c14 bank;
};
struct MapPosition020a9c14 { int x; int y; int z; };
typedef void (*MapEntryCall020a9c14)(char*, const void*, int, MapPosition020a9c14, unsigned int, unsigned int);

// USA: func_020a9c14
extern "C" ARM int func_020a9c14(const void* saved) {
    GameState* state = GameState::GetInstance();
    SavedMapList020a9c14* list = &((GameMapList020a9c14*)state)->bank.mapList;
    memcpy(list, saved, 0xad6);
    TreasureMapMetadata* map = list->maps;
    int index = 0;
    while (index < 99) {
        if (map->GetInitialByteUnknownBit()) break;
        if (index == 98) return 1;
        index++;
        map++;
    }
    func_020a3720();
    DetailedTreasureMapData detail;
    ExportDetailedTreasureMapData(map, &detail, false, 0);
    func_020a395c();
    if (detail.mapType_ == 1) {
        reinterpret_cast<MapEntryCall020a9c14>(_Z28InitTreasureMapEntry0201165cPcPKvi15Payload0201165c)((char*)state, map, detail.entranceZoneID_, *reinterpret_cast<MapPosition020a9c14*>(&detail.entranceX_), detail.regular_.environ_, detail.regular_.startingMonsterRank_);
    } else if (detail.mapType_ == 2) {
        reinterpret_cast<MapEntryCall020a9c14>(_Z28InitTreasureMapEntry0201165cPcPKvi15Payload0201165c)((char*)state, map, detail.entranceZoneID_, *reinterpret_cast<MapPosition020a9c14*>(&detail.entranceX_), 0, 0);
    }
    GrottoStruct* grotto = state->GetGrottoStruct();
    strcpy(grotto->activeMapImageName, detail.mapImageName_);
    if (detail.mapType_ == 1) {
        sprintf(grotto->activeMapNameNoLevel, detail.regular_.nameNoLevel_);
        grotto->activeMapLevel = detail.regular_.level_;
    } else if (detail.mapType_ == 2) {
        sprintf(grotto->activeMapNameNoLevel, detail.legacy_.mapNameNoLevel_);
        grotto->activeMapLevel = detail.legacy_.level_;
    }
    return 1;
}
