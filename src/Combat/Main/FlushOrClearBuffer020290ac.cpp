#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"
#include "System/LoadToVRAM.h"

#if defined(jpn)
#define FlushOrClearBuffer020290ac func_0202898c
#endif


#if defined(jpn)
extern "C" ARM void func_0202898c(int isSub);
#endif

// USA: func_020290ac
ARM void FlushOrClearBuffer020290ac(int isSub) {
    if (glyphBitmapContext.buffer == NULL) return;
    if (isSub == 0) {
        LoadToMainBG1CharacterData(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
    } else {
        LoadToSubBG0CharacterData(glyphBitmapContext.buffer, 0, 256 * 192 / 2);
    }
}
