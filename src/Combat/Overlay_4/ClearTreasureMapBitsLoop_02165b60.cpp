#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"

void ClearAllTreasureMapUnknownBits(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern char* data_ov004_02171010;

// USA: func_ov004_02165b60
ARM int ClearTreasureMapBitsLoop_02165b60(void* a) {
#if defined(jpn)
    enum { fieldOffset = 0x9f4 };
#else
    enum { fieldOffset = 0x8f4 };
#endif
    ClearAllTreasureMapUnknownBits(GameState::GetInstance());
    for (int i = 0; i < *(unsigned char*)(data_ov004_02171010 + 0x1000 + fieldOffset); i++) {
        ((TreasureMapMetadata*)(data_ov004_02171010 + i * 0x1c))->ClearInitialByteUnknownBit();
    }
    func_ov011_021848a0(a, 0x65);
    return 0;
}
