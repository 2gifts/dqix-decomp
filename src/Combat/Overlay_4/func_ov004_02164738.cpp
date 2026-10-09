#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/Memory.h"
#include "std_library_functions.h"

struct Struct020263e4;
struct Info02011930;

int CopyToBattleRegion0x64f4(void* arg);
extern "C" void* func_02012fe4(void);
extern "C" void _Z18FreeBuffer020263e4P14Struct020263e4(Struct020263e4* buf);
void SetByteFieldAt0x764(unsigned char* buf, unsigned char val);
extern "C" void _Z29SetCombatModeFromCase020dc2d0i(int mode);
extern "C" void* func_ov011_021845f8(void* obj, int idx);
extern "C" void _Z28ReleaseBattleBuffers020a39d8P13SafeAllocator(SafeAllocator* alloc);
extern "C" unsigned char _Z32GetAndConsumeNameEntries02011930PvP12Info02011930S_S_(void* obj, struct Info02011930* info, void* name1, void* name2);
extern "C" void* func_0205ec34(void);
extern "C" int _Z28LookupAndForEachNode020649b0PviS_(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
extern "C" int _Z22IsValueInRange0201b5d8i(int x);
extern "C" void _Z19InitContext020e1154Pv(void* obj);
void ResetState(void* obj);
void ClearByte0x6480(void* obj);
extern "C" void _Z25ClearRegion0x649e02011ad4Pc(char* obj);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);

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

    save.numMaps = *(unsigned char*)(data_ov004_02171010 + 0x1000 + 0x8f4);
    for (i = 0; i < 99; i++) {
        VectorizedInvertedMemcpy(data_ov004_02171010 + i * sizeof(TreasureMapMetadata), &save.maps[i], sizeof(TreasureMapMetadata));
    }
    CopyToBattleRegion0x64f4(&save);

    GameState* state = GameState::GetInstance();
    char* zone = (char*)func_02012fe4();
    GameResources* res = func_ov017_0218b5b0();
    unsigned char* buf = (unsigned char*)res->unknown_ptr_36d0;
    res->unknown_41c8[0x42e0 - 0x41c8] = *(unsigned char*)(data_ov004_02171010 + 0x1000 + 0x8fb);
    _Z18FreeBuffer020263e4P14Struct020263e4((Struct020263e4*)buf);
    SetByteFieldAt0x764(buf, 0);
    *(int*)(buf + 0x14) = *(int*)(data_ov004_02171010 + 0x1000 + 0x910);
    strcpy(zone + 0x26, data_ov004_02171010 + 0x18ff);
    res->allocator_array_38[12].Reset();
    _Z29SetCombatModeFromCase020dc2d0i(0);

    for (i = 0; i < 8; i++) {
        ((DetailedTreasureMapData*)(data_ov004_02171010 + 0xad4 + i * 0x1c4))->BlankFunction();
    }

    char* owner = (char*)func_ov011_021845f8(a, 0);
    if (owner != NULL && data_ov004_02171010 != NULL) {
        ((SafeAllocator*)(owner + 4))->Free(data_ov004_02171010);
        data_ov004_02171010 = NULL;
        _Z28ReleaseBattleBuffers020a39d8P13SafeAllocator((SafeAllocator*)(owner + 4));
    }

    if (_Z32GetAndConsumeNameEntries02011930PvP12Info02011930S_S_(state, NULL, NULL, NULL) != 0) {
        if (*((unsigned char*)state + 0x6000 + 0x4de) != 0) {
            if (_Z28LookupAndForEachNode020649b0PviS_(func_0205ec34(), 0x1b, request)) {
                func_0206f81c(request);
            }
        }
        if (_Z22IsValueInRange0201b5d8i(*(unsigned short*)zone)) {
            _Z19InitContext020e1154Pv((void*)0x7d0);
        }
    }

    ResetState(state);
    ClearByte0x6480(state);
    _Z25ClearRegion0x649e02011ad4Pc((char*)state);
    *(unsigned char*)(_Z26GetGlobalField0x1c020421a0v() + 0x1000 + 0x962) = 0;
    return 0;
}
