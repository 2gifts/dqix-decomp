#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

// USA: func_0204166c
ARM void ResetState0204166c(MessageGlyphSlot* slot) {
    slot->pixels = NULL;
    slot->textureOffset = 0;
    slot->bitmapIndex = -1;
    slot->x = 0;
    slot->y = 0;
    slot->depth = 0;
#if defined(jpn)
    slot->encodedCharacter[1] = 0;
    slot->encodedCharacter[0] = 0;
    slot->fontPixelSize = 12;
    slot->pendingUpload = 0;
    slot->renderFlag1 = 0;
    slot->renderFlag2 = 0;
#else
    slot->character = NULL;
    slot->pendingUpload = 0;
    slot->renderFlag1 = 0;
    slot->renderFlag2 = 0;
    slot->fontIndex = 0;
    slot->characterIndex = 0;
#endif
}
