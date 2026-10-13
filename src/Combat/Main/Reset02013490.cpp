#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Matrix.h"


struct GrottoTileMapRecord {
    int unknown0;
    short unknown4;
    unsigned char unknown6[9];
    unsigned char unknownF[5];
    Matrix3x3 transform;
    int unknown38;
    int unknown3c;
    int unknown40;
    int unknown44;
};

#if defined(jpn)
#define Reset02013490 func_02013258
extern "C" ARM void Reset02013490(char*);
#endif

// USA: func_02013490
ARM void Reset02013490(char* storage) {
    GrottoTileMapRecord* record = reinterpret_cast<GrottoTileMapRecord*>(storage);
    record->unknown0 = 0;
    record->unknown38 = 0;
    record->unknown4 = 0;
    memset(record->unknown6, 0, sizeof(record->unknown6));
    memset(record->unknownF, 0, sizeof(record->unknownF));
    Mat3x3_WriteIdentity(&record->transform);
    record->unknown3c = 0;
    record->unknown40 = 0;
    record->unknown44 = 0;
}
