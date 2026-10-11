#include <globaldefs.h>
#include "Grotto/Main/GrottoStruct.h"

// USA: func_020117cc
ARM void DispatchAndSetTreasureMapUnknownBit(char* obj, int arg) {
#if defined(jpn)
    ((GrottoStruct*)(obj + 0x6184))->LoadActiveMetadataFromDetailed((DetailedTreasureMapData*)arg);
#else
    ((GrottoStruct*)(obj + 0x63e4))->LoadActiveMetadataFromDetailed((DetailedTreasureMapData*)arg);
#endif
#if defined(jpn)
    ((TreasureMapMetadata*)(obj + 0x61d0))->SetInitialByteUnknownBit();
#else
    ((TreasureMapMetadata*)(obj + 0x6450))->SetInitialByteUnknownBit();
#endif
}
