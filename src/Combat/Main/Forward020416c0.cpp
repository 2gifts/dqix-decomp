#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

#if defined(jpn)
// USA: func_020416c0
extern "C" ARM void func_02041bbc(MessageGlyphSlot* slot) {
    slot->pixels = NULL;
    slot->textureOffset = 0;
    slot->bitmapIndex = -1;
    slot->x = 0;
    slot->y = 0;
    slot->depth = 0;
    slot->encodedCharacter[1] = 0;
    slot->encodedCharacter[0] = 0;
    slot->fontPixelSize = 12;
    slot->pendingUpload = 0;
    slot->renderFlag1 = 0;
    slot->renderFlag2 = 0;
}
#else
// USA: func_020416c0
ARM void Forward020416c0(MessageGlyphSlot* slot) {
    ResetState0204166c(slot);
}
#endif
