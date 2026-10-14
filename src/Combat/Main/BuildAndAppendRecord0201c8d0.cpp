#include <globaldefs.h>
#include "std_library_functions.h"
#include "World/ZoneWarpScript.h"

// USA: func_0201c8d0
ARM int WarpScript_Opcode_7e_0201c8d0(Script::Parameter* src, int numParams) {
    TileFeaturePlacementData elem;
    elem.tileID = src->ToInt();
    Script::Parameter* strFieldPtr = src + 1;
    src += 2;
    strcpy(elem.tilename, strFieldPtr->ToString());
    int i;
    for (i = 0; i < 9; i++) {
        elem.directionBitmasks[i] = src->ToInt();
        src++;
    }
    data_020fdc20.warp->CreateGrottoTileFeaturePlacementEntry_0201e3c4(elem);
    return 1;
}
