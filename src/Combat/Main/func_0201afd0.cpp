#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/ZoneFeatures.h"
#include "World/ZoneChest.h"
#include "World/LootableContainer.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Memory.h"
#include "std_library_functions.h"

struct ChestLoot0201afd0 {
    unsigned short uniqueID;
    unsigned short itemIDOrRank;
    unsigned short unk_4_0 : 2;
    unsigned short lootType : 2;
    unsigned short containerType : 3;
    short unk_6;
    Vector3i position;
};

struct ChestLootList0201afd0;

struct AdjacencyBits0201afd0 {
    unsigned char bits;
};

struct NarcName0201afd0 {
    char name[11];
};

struct TimeStamp020105a8;
struct EntryList_1e690;
struct Entry_1e690;
struct ClearThreeWords02094d00Struct;
struct AllocDest02094cdc;
struct S_02011430;
struct Container02094d14;
struct Elem02094d14;
extern "C" void* func_0202ae18();
void ComputeElapsedTime020105a8(TimeStamp020105a8*, int*);
int GenerateGrottoObjectPositionOrientation(void*, int, int, int*, int*, const TileFeaturePlacementData*, bool);
Entry_1e690* FindEntryById(EntryList_1e690*, int);
void ClearThreeWords02094d00(ClearThreeWords02094d00Struct*);
void AllocateArray02094cdc(AllocDest02094cdc*, int, SafeAllocator*);
int GetBit5cd0(S_02011430*, int, int);
int CheckField0NonZero(int*);
void CopyElemToIndex(Container02094d14*, Elem02094d14*, int);
void ZeroInit020de848(void*);
extern "C" int func_020de9a4(void*, SafeAllocator*, void*, unsigned int, unsigned short*, unsigned short);
extern "C" void __clear(void*, int);

#if defined(jpn)
extern "C" int func_020e0484(void*, SafeAllocator*, const char*, unsigned short*, unsigned short, bool);
#define data_020e6df0 data_020e7694
#endif

extern const unsigned char data_020e6e44[15];
extern const NarcName0201afd0 data_020e6df0;
extern const char* data_020f2a38;
extern const char* data_020f2a30;

static inline GrottoTilePoint GetChestTile0201afd0(const FloorMap* map, unsigned char index) {
    return map->chests[index];
}

static inline int FxSquare0201afd0(int a) {
    return (int)(((long long)a * a + 0x800) >> 12);
}

static inline AdjacencyBits0201afd0 GetAdjacency0201afd0(const FloorMap* map, int x, int y) {
    AdjacencyBits0201afd0 result;
    result.bits = map->GetAdjacencyBits(x, y);
    return result;
}

static inline int GetFloorSeed0201afd0(const ActiveGrottoClass* grotto, int floor) {
    unsigned short seed = grotto->GetActiveGrottoSeed();
    return seed + floor;
}

// USA: func_0201afd0
extern "C" ARM int func_0201afd0(Zone3D* zone, const void* treasureArchive, unsigned int sourceSize, int unused) {
    ZoneFeatures* features = &zone->substruct_6c_;
    GameState* gs = GameState::GetInstance();
    ActiveGrottoClass* grotto = &zone->grotto_;
    int i;
    FloorMap* map = &grotto->floorMap_;
    void* search = func_0202ae18();
    ChestLootList0201afd0* lootList = (ChestLootList0201afd0*)(zone->unknown_struct_2724_);

    zone->numChests_ = map->chestCount;
    if (zone->numChests_ == 0) {
        int elapsed;

        ComputeElapsedTime020105a8((TimeStamp020105a8*)(gs), &elapsed);
        srand(elapsed + GetFloorSeed0201afd0(grotto, zone->currentGrottoFloor_23ba_));
        return 0;
    }

    zone->unknown_47c_ = (ZoneChestRenderRecord*)zone->pAllocator_68_->Allocate(zone->numChests_ * sizeof(ZoneChestRenderRecord));
    features->AllocateOpcode6aEntries(zone->numChests_, zone->pAllocator_68_);
    srand(GetFloorSeed0201afd0(grotto, zone->currentGrottoFloor_23ba_));

    for (i = 0; i < zone->numChests_; i++) {
        ZoneFeatures::Opcode6aEntry entry;
        GrottoTilePoint tile;
        AdjacencyBits0201afd0 adjacency;
        int dir;
        int found;

        VectorizedMemset(&entry, 0, sizeof(entry));
        entry.unk_20 = 0;
        entry.unk_22 = 0;
        entry.unk_24 = 0;
        entry.unk_8.vec.x = 0;
        entry.unk_8.vec.y = 0;
        entry.unk_8.vec.z = 0;
        entry.unk_28 = 0;
        entry.pNext = NULL;

        entry.unk_0 = i;
        entry.unk_14.vec.z = 0x1000;
        entry.unk_14.vec.y = 0x1000;
        entry.unk_14.vec.x = 0x1000;
        entry.maybeType = 1;

        tile = GetChestTile0201afd0(map, i);
        dir = GenerateGrottoObjectPositionOrientation(
            zone, (unsigned char)(tile.x), (unsigned char)(tile.y), &entry.unk_8.vec.x, &entry.unk_8.vec.z, NULL, false);
        adjacency = GetAdjacency0201afd0(map, (unsigned char)(tile.x), (unsigned char)(tile.y));
        found = 0;
        if (grotto->GetActiveGrottoEnviron() == 2) {
            for (int j = 0; j < 15; j++) {
                if (adjacency.bits == data_020e6e44[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                entry.unk_8.vec.y = -0x4cc;
            }
        }

        switch (dir) {
        case 0:
            entry.unk_20 = entry.unk_22 = 0x3244;
            break;
        case 1:
            entry.unk_20 = entry.unk_22 = 0x1922;
            break;
        case 2:
            entry.unk_20 = entry.unk_22 = 0;
            break;
        case 3:
            entry.unk_20 = entry.unk_22 = 0x4b66;
            break;
        }

        {
            fix32_t halfX = entry.unk_14.vec.x / 2;
            fix32_t halfZ = entry.unk_14.vec.z / 2;
            fix32_t zSq = FxSquare0201afd0(halfZ);
            fix32_t xSq = FxSquare0201afd0(halfX);

            entry.unk_24 = xSq + zSq;
        }
        entry.pNext = NULL;
        features->CreateOpcode6aEntry(entry);
    }

    {
        SafeAllocator alloc;
        char buffer[0x400];
        LootDistribution distribution;
        NarcName0201afd0 name;
        const void* script;
        unsigned int scriptLength;
        int ranks[32];
        unsigned short itemIDs[100];
        int elapsed;
        int itemCount;
        int chest;
        int index;

        alloc.ResetAllocatorPointer();
        alloc.CreateTypeA(buffer, sizeof(buffer));
        name = data_020e6df0;
        if (GetFileInNarcPermissive(treasureArchive, name.name, &script, &scriptLength)) {
            distribution.Reset();
            distribution.LoadFromScript(&alloc, script, scriptLength);
        }

        ClearThreeWords02094d00((ClearThreeWords02094d00Struct*)(lootList));
        AllocateArray02094cdc((AllocDest02094cdc*)(lootList), zone->numChests_, zone->pAllocator_68_);
        memset(ranks, 1, sizeof(ranks));
        for (chest = 0; chest < zone->numChests_; chest++) {
            ranks[chest] = grotto->RandomizeChestRank(zone->currentGrottoFloor_23ba_);
        }

        ComputeElapsedTime020105a8((TimeStamp020105a8*)(gs), &elapsed);
        srand(elapsed + GetFloorSeed0201afd0(grotto, zone->currentGrottoFloor_23ba_));

        __clear(itemIDs, sizeof(itemIDs));
        itemCount = 0;
        for (index = 0; index < zone->numChests_; index++) {
            ZoneFeatures::Opcode6aEntry* entry = (ZoneFeatures::Opcode6aEntry*)(FindEntryById((EntryList_1e690*)(features), index));
            const LootDistribution::Outcome* outcome = distribution.Sample(ranks[index]);

            if (outcome != NULL) {
                ZoneChestRenderRecord* record = &zone->unknown_47c_[index];
                ChestLoot0201afd0 loot;

                InitStruct020133fc(record);
                record->position = entry->unk_8.vec;
                record->angleY = entry->unk_20;
                record->counter = 0;
                record->recordIndex = index;
                record->uniqueID = index;
                record->secondPass = 2;
                if (GetBit5cd0((S_02011430*)(gs), zone->currentGrottoFloor_23ba_, index)) {
                    record->active = 8;
                    record->angleX = 0x4000;
                } else {
                    record->active = 1;
                    record->angleX = 0x647a;
                }
                if (CheckField0NonZero((int*)(search))) {
                    record->special = 1;
                }
                if (outcome->lootType == 2) {
                    itemIDs[itemCount++] = outcome->itemID;
                }

                loot.uniqueID = 0;
                loot.itemIDOrRank = outcome->itemID;
                loot.unk_4_0 = 0;
                loot.lootType = outcome->lootType;
                loot.containerType = 4;
                loot.position = entry->unk_8.vec;
                CopyElemToIndex((Container02094d14*)(lootList), (Elem02094d14*)(&loot), record->uniqueID);
            }
        }

        ZeroInit020de848(zone->unknown_struct_2754_);
        if (itemCount > 0) {
#if defined(jpn)
            func_020e0484(zone->unknown_struct_2754_, zone->pAllocator_68_, data_020f2a38, itemIDs, itemCount, true);
#else
            BackgroundLoader::AddLockGlobal();
            unsigned int size = 0;
            void* data = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &size);

            if (data != NULL) {
                func_020de9a4(zone->unknown_struct_2754_, zone->pAllocator_68_, data, size, itemIDs, itemCount);
            }
            BackgroundLoader::RemoveLockGlobal();
#endif
        }
        alloc.Reset();
        alloc.Destroy();
    }
    return 1;
}
