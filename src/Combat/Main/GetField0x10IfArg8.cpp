#include <globaldefs.h>
#include "Resource/FontGlyphTable.h"

struct FontTableGlobals {
#if defined(jpn)
    char unknown0[0x14];
    FontGlyphTable* font6;
    char unknown18[8];
    FontGlyphTable* font8;
    FontGlyphTable* font10;
    FontGlyphTable* font12;
#else
    char unknown0[0x10];
    FontGlyphTable* font8;
#endif
};

extern FontTableGlobals data_02107800;

// USA: func_020429bc
ARM FontGlyphTable* GetFontGlyphTable_020429bc(int pixelSize) {
    FontGlyphTable* table = NULL;
#if defined(jpn)
    switch (pixelSize) {
    case 6: table = data_02107800.font6; break;
    case 8: table = data_02107800.font8; break;
    case 10: table = data_02107800.font10; break;
    case 12: table = data_02107800.font12; break;
    }
#else
    if (pixelSize == 8) table = data_02107800.font8;
#endif
    return table;
}
