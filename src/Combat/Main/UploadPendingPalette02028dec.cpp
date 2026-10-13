#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"

#include "std_library_functions.h"
#include "System/LoadToVRAM.h"
#include "System/Cache.h"
#include "System/Graphics.h"

extern "C" void func_02028e90();
extern "C" void func_02028f54();

extern unsigned char data_020e7390[0x20];

// USA: func_02028dec
ARM void UploadPendingPalette02028dec(int isSub) {
    if (glyphBitmapContext.buffer == NULL) {
        return;
    }
    memcpy(glyphBitmapContext.buffer, data_020e7390, 0x20);
    CleanInvalidateCacheRange(glyphBitmapContext.buffer, 0x20);
    if (isSub == 0) {

        BG1CNT = (BG1CNT & 0x43) | 0x4;
        LoadToMainBGStandardPalette(glyphBitmapContext.buffer, 0, 0x20);
    } else {
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0x4;
        LoadToSubBGStandardPalette(glyphBitmapContext.buffer, 0, 0x20);
    }
    func_02028e90();
    func_02028f54();
}
