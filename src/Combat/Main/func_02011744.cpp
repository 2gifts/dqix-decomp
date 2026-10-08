#include <globaldefs.h>
#include "Grotto/Main/TreasureMapMetadata.h"
#include "System/Memory.h"

int CopyOutBattleRegion0x64f4(void* dst);
int CopyToBattleRegion0x64f4(void* arg);

// USA: func_02011744
extern "C" ARM void func_02011744(void* obj) {
    if (((unsigned char*)obj)[0x63e4] == 0) {
        return;
    }

    unsigned char localBuf[0xad8];
    CopyOutBattleRegion0x64f4(localBuf);

    for (int i = 0; i < localBuf[0]; i++) {
        if (((TreasureMapMetadata*)(localBuf + 2 + i * 0x1c))->GetInitialByteUnknownBit()) {
            VectorizedInvertedMemcpy((char*)obj + 0x450 + 0x6000, localBuf + 2 + i * 0x1c, 0x1c);
            CopyToBattleRegion0x64f4(localBuf);
            return;
        }
    }
}
