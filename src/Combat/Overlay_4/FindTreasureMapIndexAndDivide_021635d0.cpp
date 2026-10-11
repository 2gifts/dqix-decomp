#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"

extern char* data_ov004_02171010;
unsigned char CopyToRegion0x6482IfDst(char* obj, void* dst);

// USA: func_ov004_021635d0
ARM int FindTreasureMapIndexAndDivide_021635d0(int* outQuotient, int* outRemainder) {
#if defined(jpn)
 enum { countOffset = 0x9f4 };
#else
 enum { countOffset = 0x8f4 };
#endif
    if (outQuotient == NULL) return 0;
    if (outRemainder == NULL) return 0;
    int foundIndex = -1;
    unsigned char result = CopyToRegion0x6482IfDst((char*)GameState::GetInstance(), NULL);
    int i;
    if (result != 0) {
        for (i = 0; i < *(unsigned char*)(data_ov004_02171010 + 0x1000 + countOffset); i++) {
            TreasureMapMetadata* meta = (TreasureMapMetadata*)(data_ov004_02171010 + i * 0x1c);
            if (meta->GetDiscoveryState() == DiscoveryState_Cleared) {
                foundIndex = i;
                break;
            }
        }
    } else {
        for (i = 0; i < *(unsigned char*)(data_ov004_02171010 + 0x1000 + countOffset); i++) {
            TreasureMapMetadata* meta = (TreasureMapMetadata*)(data_ov004_02171010 + i * 0x1c);
            if (meta->GetInitialByteUnknownBit()) {
                foundIndex = i;
                break;
            }
        }
    }
    if (foundIndex < 0) return 0;
    int q = foundIndex / 8;
    int rem = foundIndex - q * 8;
    if (rem < 0) rem = 0;
    *outQuotient = q;
    *outRemainder = rem;
    return 1;
}
