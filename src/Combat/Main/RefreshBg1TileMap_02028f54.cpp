#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"
#include "Graphics/GlyphMetrics.h"

#include "std_library_functions.h"
#include "System/LoadToVRAM.h"

#include "System/Cache.h"


// USA: func_02028f54  (semantic: RefreshBg1TileMap_02028f54)
extern "C" ARM void func_02028f54(void) {
    if (glyphBitmapContext.buffer == 0) {
        return;
    }

    if (glyphBitmapContext.buffer != 0) {
        memset(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
    }
    unsigned short* screenEntry = static_cast<unsigned short*>(glyphBitmapContext.buffer);
    unsigned short tile = 0;
    int row;
    int col;
    for (row = 0; row < 24; row++) {
        for (col = 0; col < 32; col++) {
            *screenEntry = tile;
            screenEntry++;
            tile++;
        }
    }
    int mode = data_020ef74c.displayMode;
    CleanInvalidateCacheRange(glyphBitmapContext.buffer, 32 * 24 * sizeof(unsigned short));
    if (mode == 3) {
        LoadToMainBG1ScreenData(glyphBitmapContext.buffer, 0, 32 * 24 * sizeof(unsigned short));
        return;
    }
    if (mode == 4) {
        LoadToSubBG0ScreenData(glyphBitmapContext.buffer, 0, 32 * 24 * sizeof(unsigned short));
        return;
    }
    if (mode == 5) {
        LoadToMainBG1ScreenData(glyphBitmapContext.buffer, 0, 32 * 24 * sizeof(unsigned short));
        return;
    }
    if (mode == 6) {
        LoadToSubBG0ScreenData(glyphBitmapContext.buffer, 0, 32 * 24 * sizeof(unsigned short));
        return;
    }
}
