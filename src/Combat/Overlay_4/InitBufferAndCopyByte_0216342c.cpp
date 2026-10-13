#include <globaldefs.h>
#include "System/Memory.h"
#include "Resource/GameResources.h"
#include "Grotto/Main/DetailedTreasureMapData.h"

struct MapSelectionBuffer {
    TreasureMapMetadata maps[99];
    DetailedTreasureMapData details[8];
    unsigned char entryCount;
    unsigned char unknownF5;
    short page;
    short pageCount;
    unsigned char savedByte;
    unsigned char unknownFB;
    unsigned char mode;
    unsigned char flagFD;
    unsigned char unknownFE;
    unsigned char unknownFF[0x15];
};

#if defined(jpn)
// USA: func_ov004_0216342c
extern "C" ARM void func_ov004_02163a20(void* a) {
#else
// USA: func_ov004_0216342c
ARM void InitBufferAndCopyByte_0216342c(void* a) {
#endif
    GameResources* resources = func_ov017_0218b5b0();
    VectorizedMemset(a, 0, sizeof(MapSelectionBuffer));
    MapSelectionBuffer* buffer = (MapSelectionBuffer*)a;
    buffer->savedByte = ((unsigned char*)resources->unknown_41c8)[0x118];
    buffer->unknownFB = 0;
    buffer->mode = 0;
    buffer->flagFD = 0;
    buffer->unknownFE = 0;
}
