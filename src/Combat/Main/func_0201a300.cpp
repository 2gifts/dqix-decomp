#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"

struct InitStruct;
struct Array020286fc;
struct Array02028754;
struct Array0202834c;
struct BoundedHalfwordPairList;
struct Container02028170;
struct List_020283c0;
struct AppendPairList;
struct TimeStamp020105a8;
struct Elem02028170 {
    unsigned char id;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char flags;
    unsigned short x;
    unsigned short field_6;
    unsigned short z;
    int field_c;
};
struct AppendEntry { Elem02028170* first; Elem02028170* second; };
struct HalfwordPair { unsigned short first; unsigned short second; };
struct GrottoTileLists0201a300 { unsigned char data[0x2c]; };
struct GrottoTileOwner0201a300 {
    unsigned short seed;
    char pad_2[0xe];
    SafeAllocator* allocator;
    int field_14;
    GrottoTileLists0201a300 lists;
};
struct GrottoFrame0201a300 {
    int elapsed;
    int z;
    int x;
    AppendEntry pair;
    HalfwordPair origin;
    Elem02028170 feature;
    unsigned char tiles[256];
};
void InitializeStruct020280f8(InitStruct*);
void InitializeStruct(InitStruct*);
void AllocateAndClearHeaderArray020286fc(Array020286fc*, SafeAllocator*, int);
void AllocateClearArray02028754(Array02028754*, SafeAllocator*, int);
void AllocateArray0202834c(Array0202834c*, SafeAllocator*, int);
void AppendHalfwordPairCapped(BoundedHalfwordPairList*, HalfwordPair*);
int GenerateGrottoObjectPositionOrientation(void*, int, int, int*, int*, const TileFeaturePlacementData*, bool);
void AppendCappedElement02028170(Container02028170*, Elem02028170*);
Elem02028170* FindListEntryById(List_020283c0*, int);
void AppendPairToBoundedList(AppendPairList*, AppendEntry*);
extern "C" void func_02028214(GrottoTileLists0201a300*, SafeAllocator*);
void ComputeElapsedTime020105a8(TimeStamp020105a8*, int*);

static inline unsigned int GrottoTileId0201a300(unsigned int x, unsigned int y) {
    unsigned int id = x + (y << 4);
    return id;
}

// USA: func_0201a300
extern "C" ARM int func_0201a300(Zone3D* zone, int floor, GrottoTileOwner0201a300* owner, const TileFeaturePlacementData* placements, FloorMap* map) {
    GameState* state = GameState::GetInstance();
    if (!owner) return 1;
    srand(owner->seed % 20);
    GrottoFrame0201a300 frame;
    FloorMap* sourceMap = map ? map : &zone->grotto_.floorMap_;
    memcpy(frame.tiles, sourceMap->pMapData, 256);
    int count = 0;
    int neighbors = 0;
    int y;
    int x;
    unsigned int previousY;
    for (y = 1; y < 15; y++) {
        for (x = 1; x < 15; x++) {
            previousY = y;
            previousY -= 1;
            int value = frame.tiles[x + (y << 4)];
            if (value == 1 || value == 3) continue;
            int left = frame.tiles[x - 1 + (y << 4)];
            int above = frame.tiles[x + (previousY << 4)];
            if (left != 1 && left != 3) neighbors++;
            count++;
            if (above != 1 && above != 3) neighbors++;
        }
    }
    int remaining = 0x1020 - ((count << 4) + (neighbors << 3));
    if (remaining < 0) neighbors -= abs(remaining / 8) + 1;
    InitializeStruct020280f8((InitStruct*)&owner->lists);
    InitializeStruct((InitStruct*)&owner->lists);
    AllocateAndClearHeaderArray020286fc((Array020286fc*)&owner->lists, owner->allocator, count);
    AllocateClearArray02028754((Array02028754*)&owner->lists, owner->allocator, neighbors);
    AllocateArray0202834c((Array0202834c*)&owner->lists, owner->allocator, 1);
    frame.origin.first = 0;
    frame.origin.second = 0;
    AppendHalfwordPairCapped((BoundedHalfwordPairList*)&owner->lists, &frame.origin);
    for (int y = 1; y < 15; y++) {
        int previousY;
        int x = 1;
        for (; x < 15; x++) {
            previousY = y - 1;
            int value = frame.tiles[x + (y << 4)];
            int id = x + (y << 4);
            if (value == 1 || value == 3) continue;
            frame.feature.id = 0;
            frame.feature.field_1 = 0;
            frame.feature.field_2 = 0;
            frame.feature.field_c = 0;
            frame.feature.flags = 0;
            GenerateGrottoObjectPositionOrientation(zone, x, y, &frame.x, &frame.z, placements, false);
            frame.feature.field_6 = 0;
            frame.feature.x = frame.x >> 12;
            frame.feature.z = frame.z >> 12;
            if (value == 4) frame.feature.flags |= 2;
            frame.feature.id = id;
            AppendCappedElement02028170((Container02028170*)&owner->lists, &frame.feature);
            int leftId = x - 1 + (y << 4);
            int left = frame.tiles[leftId];
            int aboveId = x + (previousY << 4);
            int above = frame.tiles[aboveId];
            if (left != 1 && left != 3) {
                frame.pair.second = 0;
                frame.pair.first = 0;
                frame.pair.first = FindListEntryById((List_020283c0*)&owner->lists, GrottoTileId0201a300(x, y));
                frame.pair.second = FindListEntryById((List_020283c0*)&owner->lists, leftId);
                AppendPairToBoundedList((AppendPairList*)&owner->lists, &frame.pair);
            }
            if (above != 1 && above != 3) {
                frame.pair.second = 0;
                frame.pair.first = 0;
                frame.pair.first = FindListEntryById((List_020283c0*)&owner->lists, id);
                frame.pair.second = FindListEntryById((List_020283c0*)&owner->lists, aboveId);
                AppendPairToBoundedList((AppendPairList*)&owner->lists, &frame.pair);
            }
        }
    }
    func_02028214(&owner->lists, owner->allocator);
    ComputeElapsedTime020105a8((TimeStamp020105a8*)state, &frame.elapsed);
    srand(frame.elapsed);
    return 1;
}

