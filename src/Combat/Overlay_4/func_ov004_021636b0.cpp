#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

struct Obj021f9bb0;
struct Obj0202656c;
struct TableA68;

struct PointerBlock02171010 {
    char* base;
    char* slotBuffer;
    void* callTarget;
};

extern struct PointerBlock02171010 data_ov004_02171010;

extern "C" void* func_02012fe4(void);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int index);
extern "C" struct TableA68* func_ov023_021fa598(void* obj);
extern "C" int func_ov004_0216f8c0(unsigned short id);
extern "C" void func_02046608(int a, int b, char* text, char* slot, int c, int d, int e);
extern "C" void* __clear(void* destination, int count);

extern "C" unsigned int func_ov023_021f6f10(void* self);
int GetShort28_021f9bb0(struct Obj021f9bb0* obj);
void CopyStringOrDefault02026428(void* dst, const char* src);
void SetEventStringAndAccumulateLength02026470(void* dst, int value);
void SetString020264e4(char* dst, char* src);
void SetString02026528(char* dst, char* src);
void SetField766AndNotify0202656c(struct Obj0202656c* obj, int value);
int GetGlobalField0x1c020421a0(void);
void SetIndexedRecord020265a8(char* dst, int index, const char* name, int rate);
void* FindEntryByKey(struct TableA68* table, int key);
void CopyTextAndUppercaseIfFlagged0206819c(const char* source, char* destination, int tableIndex);
void* CallFunc020e52a0(void* obj, int index);
void SetBoolFlag020263c8(unsigned char* obj, int value);
void SetByteFieldAt0x764(unsigned char* buf, unsigned char val);
void RestartTaskWithDebugLog020dc3d4(void);

#if defined(jpn)
extern "C" void func_02025dfc(void*, const char*);
extern "C" void func_02025e2c(void*, int);
extern "C" void func_02025e64(char*, char*);
extern "C" void func_02025e9c(char*, char*);
extern "C" void func_02025ed4(Obj0202656c*, int);
extern "C" void func_02025f0c(char*, int, const char*, int);
extern "C" void func_02025d9c(unsigned char*, int);
#define CopyStringOrDefault02026428 func_02025dfc
#define SetEventStringAndAccumulateLength02026470 func_02025e2c
#define SetString020264e4 func_02025e64
#define SetString02026528 func_02025e9c
#define SetField766AndNotify0202656c func_02025ed4
#define SetIndexedRecord020265a8 func_02025f0c
#define SetBoolFlag020263c8 func_02025d9c
extern "C" int func_ov004_0216ff54(unsigned short id, char* text);
extern "C" void func_02041f50(const char* src, char* dst);
struct MapBlock021636b0 {
    char pad0[0xad4];
    DetailedTreasureMapData maps[1];
    unsigned char GetTreasureDropRate(int index) const {
        const unsigned char* rates = maps[0].treasureDropRates_;
        return rates[index];
    }
};
#define CURRENT_MAP (&((MapBlock021636b0*)data_ov004_02171010.base)->maps[idx])
#define MAP_TYPE (*(unsigned char*)(data_ov004_02171010.base + 0xad5 + recordOffset))
#define REGULAR_DATA ((DetailedTreasureMapData::RegularMapData*)(data_ov004_02171010.base + 0xb20 + recordOffset))
#define LEGACY_DATA ((DetailedTreasureMapData::LegacyBossMapData*)(data_ov004_02171010.base + 0xb20 + recordOffset))
#define TREASURE_MAP (&((MapBlock021636b0*)(data_ov004_02171010.base + recordOffset))->maps[0])
#else
#define CURRENT_MAP det
#define MAP_TYPE det->mapType_
#define REGULAR_DATA (&det->regular_)
#define LEGACY_DATA (&det->legacy_)
#endif

// USA: func_ov004_021636b0
extern "C" ARM void func_ov004_021636b0(void* a0, const char* a1) {
#if !defined(jpn)
    char bufB[0x80];
#endif
    char bufA[0x80];

    char* zone = (char*)func_02012fe4();
    DetailedTreasureMapData* det;
    void* ov011;
    char* slot;
    struct TableA68* table;
    unsigned char* buf;
    unsigned int recordOffset;
    GameResources* res = func_ov017_0218b5b0();
    buf = (unsigned char*)res->unknown_ptr_36d0;
    strcpy(zone + 0x26, a1);
    RestartTaskWithDebugLog020dc3d4();
    SetByteFieldAt0x764(buf, 1);
    *(int*)(buf + 0x14) = 1;

    void* obj = func_ov023_021f6880(func_ov011_021849c8(a0), 0xa);
    if (obj == NULL) return;
    if (func_ov023_021f6f10(obj) != 7) return;

    int idx = GetShort28_021f9bb0((struct Obj021f9bb0*)obj);
#if defined(jpn)
    recordOffset = idx * sizeof(DetailedTreasureMapData);
#endif
    det = (DetailedTreasureMapData*)(data_ov004_02171010.base + 0xad4 + idx * 0x1c4);

    if (MAP_TYPE == 1) {
        CopyStringOrDefault02026428(buf, REGULAR_DATA->nameNoLevel_);
        SetEventStringAndAccumulateLength02026470(buf, REGULAR_DATA->level_);
    } else if (MAP_TYPE == 2) {
        CopyStringOrDefault02026428(buf, LEGACY_DATA->mapNameNoLevel_);
        SetEventStringAndAccumulateLength02026470(buf, LEGACY_DATA->level_);
    }
    SetString020264e4((char*)buf, CURRENT_MAP->discoveredBy_);
    SetString02026528((char*)buf, CURRENT_MAP->clearedBy_);
    if (CURRENT_MAP->mapType_ == 2) {
        SetField766AndNotify0202656c((struct Obj0202656c*)buf, LEGACY_DATA->minTurns_);
    }

    ov011 = func_ov011_021849c8(a0);
#if defined(jpn)
    void* obj2 = func_ov023_021f6880(ov011, 0x258);
    if (obj2 == NULL) return;
    if (func_ov023_021f6f10(obj2) != 4) return;
    table = func_ov023_021fa598(obj2);
    for (int i = 0; i < 3; i++) {
        __clear(bufA, sizeof(bufA));
        if (TREASURE_MAP->discoveredTreasures_[i] == 0) {
            SetIndexedRecord020265a8((char*)buf, (unsigned char)i, NULL, TREASURE_MAP->treasureDropRates_[i]);
            continue;
        }
        if (!func_ov004_0216ff54(TREASURE_MAP->treasureItemIDs_[i], bufA)) {
            const char* name = (const char*)FindEntryByKey(table, (short)TREASURE_MAP->treasureItemIDs_[i]);
            if (name != NULL) {
                func_02041f50(name, bufA);
            }
        }
        unsigned char rate = ((MapBlock021636b0*)(data_ov004_02171010.base + recordOffset))->GetTreasureDropRate(i);
        SetIndexedRecord020265a8((char*)buf, (unsigned char)i, bufA, rate);
    }
#else
    memset(data_ov004_02171010.slotBuffer, 0, 0x333);

    for (int i = 0; i < 3; i++) {
        __clear(bufB, 0x80);
        __clear(bufA, 0x80);
        int tableRoot = GetGlobalField0x1c020421a0();
        if (det->discoveredTreasures_[i] == 0) {
            SetIndexedRecord020265a8((char*)buf, (unsigned char)i, NULL, det->treasureDropRates_[i]);
            continue;
        }

        slot = data_ov004_02171010.slotBuffer + i * 0x80;
        memset(slot, 0, 0x80);
        int key = func_ov004_0216f8c0(det->treasureItemIDs_[i]);
        if (key != 0) {
            void* obj2 = func_ov023_021f6880(ov011, 0x32);
            if (obj2 == NULL) return;
            if (func_ov023_021f6f10(obj2) != 4) return;
            struct TableA68* table = func_ov023_021fa598(obj2);
            CopyTextAndUppercaseIfFlagged0206819c((const char*)FindEntryByKey(table, (short)key), bufA, 0);
            func_02046608(tableRoot, 0, bufA, slot, 0x60, 0, 0);
        } else {
            char** entry = (char**)CallFunc020e52a0(data_ov004_02171010.callTarget, (short)det->treasureItemIDs_[i]);
            CopyTextAndUppercaseIfFlagged0206819c(*entry, bufA, 0);
            func_02046608(tableRoot, 0, bufA, slot, 0x60, 0, 0);
        }
        SetIndexedRecord020265a8((char*)buf, (unsigned char)i, slot, det->treasureDropRates_[i]);
    }

#endif
    SetBoolFlag020263c8(buf, 1);
}
#undef CURRENT_MAP
#undef MAP_TYPE
#undef REGULAR_DATA
#undef LEGACY_DATA
#undef TREASURE_MAP
