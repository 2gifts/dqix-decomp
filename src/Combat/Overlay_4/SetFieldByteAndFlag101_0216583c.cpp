#include <globaldefs.h>
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

extern char* data_ov004_02171010;
extern "C" void func_ov011_021848a0(void* obj, int val);

#if defined(jpn)
// USA: func_ov004_0216583c
extern "C" ARM int func_ov004_021660cc(void* obj) {
#else
// USA: func_ov004_0216583c
extern "C" ARM int func_ov004_0216583c(void* obj) {
#endif
    MapSelectionBuffer* buffer = (MapSelectionBuffer*)data_ov004_02171010;
    buffer->flagFD = 1;
    func_ov011_021848a0(obj, 0x65);
    return 0;
}
