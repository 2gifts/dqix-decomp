#pragma once

#include "World/Zone3D.h"

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

struct GrottoTileLists0201a300 {
    unsigned char tileCapacity;
    unsigned char pairCapacity;
    unsigned char tileCount;
    unsigned char pairCount;
    Elem02028170* tiles;
    AppendEntry* pairs;
    int unknownC;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
    int unknown20;
    unsigned char originCapacity;
    unsigned char originCount;
    unsigned char unknown26[2];
    HalfwordPair* origins;
};

// Known prefix used by the tile graph builder and its resource-load callers.
struct GrottoTileOwner0201a300 {
    unsigned short zoneId;
    unsigned char unknown2[0xa];
    unsigned char loaded;
    unsigned char unknownD[3];
    SafeAllocator* allocator;
#if !defined(jpn)
    int unknown14;
#endif
    GrottoTileLists0201a300 lists;
};

typedef char GrottoTileListsSizeCheck[sizeof(GrottoTileLists0201a300) == 0x2c ? 1 : -1];
typedef char GrottoTileElementSizeCheck[sizeof(Elem02028170) == 0x10 ? 1 : -1];
#if defined(jpn)
typedef char GrottoTileOwnerListOffsetCheck[offsetof(GrottoTileOwner0201a300, lists) == 0x14 ? 1 : -1];
#else
typedef char GrottoTileOwnerListOffsetCheck[offsetof(GrottoTileOwner0201a300, lists) == 0x18 ? 1 : -1];
#endif

extern "C" int func_0201a300(Zone3D* zone, int floor, GrottoTileOwner0201a300* owner,
                            const TileFeaturePlacementData* placements, FloorMap* map);
