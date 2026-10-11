#include <globaldefs.h>

#if defined(jpn)
enum { activeFlagOffset = 0x6184, entryOffset = 0x1d0 };
#else
enum { activeFlagOffset = 0x63e4, entryOffset = 0x450 };
#endif
#include "Grotto/Main/TreasureMapMetadata.h"
#include "System/Memory.h"

int CopyOutBattleRegion0x64f4(void* dst);
int CopyToBattleRegion0x64f4(void* arg);

// USA: func_02011744
extern "C" ARM void func_02011744(void* obj) {
    if (((unsigned char*)obj)[activeFlagOffset] == 0) {
        return;
    }

    unsigned char localBuf[0xad8];
    CopyOutBattleRegion0x64f4(localBuf);

    for (int i = 0; i < localBuf[0]; i++) {
        if (((TreasureMapMetadata*)(localBuf + 2 + i * 0x1c))->GetInitialByteUnknownBit()) {
            VectorizedInvertedMemcpy((char*)obj + entryOffset + 0x6000, localBuf + 2 + i * 0x1c, 0x1c);
            CopyToBattleRegion0x64f4(localBuf);
            return;
        }
    }
}
