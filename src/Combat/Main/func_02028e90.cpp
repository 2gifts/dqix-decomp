#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"

#include "std_library_functions.h"
#include "System/LoadToVRAM.h"
#include "System/Cache.h"

struct GfxModeState02028e90 {
    char pad[0xc];
    int mode;
};
extern struct GfxModeState02028e90 data_020ef74c;

// USA: func_02028e90  (semantic: FlushBg1TileMapByMode_02028e90)
extern "C" ARM void func_02028e90(void) {
    if (glyphBitmapContext.buffer == 0) {
        return;
    }

    if (glyphBitmapContext.buffer != 0) {
        memset(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
    }
    int mode = data_020ef74c.mode;
    CleanInvalidateCacheRange(glyphBitmapContext.buffer, 256 * 192 / 2);
    if (mode == 3) {
        LoadToMainBG1CharacterData(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
        return;
    }
    if (mode == 4) {
        LoadToSubBG0CharacterData(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
        return;
    }
    if (mode == 5) {
        LoadToMainBG1CharacterData(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
        return;
    }
    if (mode == 6) {
        LoadToSubBG0CharacterData(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
        return;
    }
}
