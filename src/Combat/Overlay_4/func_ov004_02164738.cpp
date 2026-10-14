#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/Memory.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { countOffset = 0x9f4, flagOffset = 0x9fb, valueOffset = 0xa10, nameOffset = 0x19ff, recordStride = 0x1e4, stateFlag = 0x29e, resetOffset = 0x790 };
#else
enum { countOffset = 0x8f4, flagOffset = 0x8fb, valueOffset = 0x910, nameOffset = 0x18ff, recordStride = 0x1c4, stateFlag = 0x4de, resetOffset = 0x962 };
#endif

struct Struct020263e4;
struct Info02011930;

int CopyToBattleRegion0x64f4(void* arg);
extern "C" void* func_02012fe4(void);
void FreeBuffer020263e4(Struct020263e4* buf);
void SetByteFieldAt0x764(unsigned char* buf, unsigned char val);
void SetCombatModeFromCase020dc2d0(int mode);
extern "C" void* func_ov011_021845f8(void* obj, int idx);
void ReleaseBattleBuffers020a39d8(SafeAllocator* alloc);
unsigned char GetAndConsumeNameEntries02011930(void* obj, struct Info02011930* info, void* name1, void* name2);
extern "C" void* func_0205ec34(void);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
int IsValueInRange0201b5d8(int x);
void InitContext020e1154(void* obj);
void ResetState(void* obj);
void ClearByte0x6480(void* obj);
void ClearRegion0x649e02011ad4(char* obj);
int GetGlobalField0x1c020421a0(void);

extern char* data_ov004_02171010;

struct TreasureMapSave02164738 {
    unsigned char numMaps;
    TreasureMapMetadata maps[99];
};

// USA: func_ov004_02164738
extern "C" ARM int func_ov004_02164738(void* a) {
    char request[0x34];
    TreasureMapSave02164738 save;
    int i;

    save.numMaps = *(unsigned char*)(data_ov004_02171010 + 0x1000 + countOffset);
    for (i = 0; i < 99; i++) {
        VectorizedInvertedMemcpy(data_ov004_02171010 + i * sizeof(TreasureMapMetadata), &save.maps[i], sizeof(TreasureMapMetadata));
    }
    CopyToBattleRegion0x64f4(&save);

    GameState* state = GameState::GetInstance();
    char* zone = (char*)func_02012fe4();
    GameResources* res = func_ov017_0218b5b0();
    unsigned char* buf = (unsigned char*)res->unknown_ptr_36d0;
    res->unknown_41c8[0x42e0 - 0x41c8] = *(unsigned char*)(data_ov004_02171010 + 0x1000 + flagOffset);
    FreeBuffer020263e4((Struct020263e4*)buf);
    SetByteFieldAt0x764(buf, 0);
    *(int*)(buf + 0x14) = *(int*)(data_ov004_02171010 + 0x1000 + valueOffset);
    strcpy(zone + 0x26, data_ov004_02171010 + nameOffset);
    res->allocator_array_38[12].Reset();
    SetCombatModeFromCase020dc2d0(0);

    for (i = 0; i < 8; i++) {
        ((DetailedTreasureMapData*)(data_ov004_02171010 + 0xad4 + i * recordStride))->BlankFunction();
    }

    char* owner = (char*)func_ov011_021845f8(a, 0);
    if (owner != NULL && data_ov004_02171010 != NULL) {
        ((SafeAllocator*)(owner + 4))->Free(data_ov004_02171010);
        data_ov004_02171010 = NULL;
        ReleaseBattleBuffers020a39d8((SafeAllocator*)(owner + 4));
    }

    if (GetAndConsumeNameEntries02011930(state, NULL, NULL, NULL) != 0) {
        if (*((unsigned char*)state + 0x6000 + stateFlag) != 0) {
            if (LookupAndForEachNode020649b0(func_0205ec34(), 0x1b, request)) {
                func_0206f81c(request);
            }
        }
        if (IsValueInRange0201b5d8(*(unsigned short*)zone)) {
            InitContext020e1154((void*)0x7d0);
        }
    }

    ResetState(state);
    ClearByte0x6480(state);
    ClearRegion0x649e02011ad4((char*)state);
    *(unsigned char*)(GetGlobalField0x1c020421a0() + 0x1000 + resetOffset) = 0;
    return 0;
}
