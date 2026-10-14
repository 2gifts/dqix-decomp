#include <globaldefs.h>

#if defined(jpn)
enum { activeFlagOffset = 0x6184, secondFlagOffset = 0x6185 };
#else
enum { activeFlagOffset = 0x63e4, secondFlagOffset = 0x63e5 };
#endif
#include "Grotto/Main/TreasureMapMetadata.h"

int CopyOutBattleRegion0x64f4_020ac760(void* dst);
int CopyToBattleRegion0x64f4_020ac734(void* arg);

extern "C" {
    void func_ov017_021cfabc(void);
    void func_ov017_021cf730(int, int);
}

// USA: func_020116c8
ARM void ClearAllTreasureMapUnknownBits_020116c8(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    p[activeFlagOffset] = 0;
    p[secondFlagOffset] = 0;

    unsigned char localBuf[0xad8];
    CopyOutBattleRegion0x64f4_020ac760(localBuf);

    for (int i = 0; i < localBuf[0]; i++) {
        ((TreasureMapMetadata*)(localBuf + 2 + i * 0x1c))->ClearInitialByteUnknownBit();
    }

    CopyToBattleRegion0x64f4_020ac734(localBuf);
    func_ov017_021cfabc();
    func_ov017_021cf730(-1, 0);
}
