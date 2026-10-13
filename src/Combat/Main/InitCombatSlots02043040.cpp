#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

#if defined(jpn)
extern "C" void func_02041bbc(MessageGlyphSlot* slot);
#define Forward020416c0 func_02041bbc
enum { FirstGlyphSlot = 14 };
#else
void Forward020416c0(MessageGlyphSlot* slot);
enum { FirstGlyphSlot = 0 };
#endif

// USA: func_02043040
ARM void InitCombatSlots02043040(MessageSystem* window) {
    memset(window->bitmapAllocationBits, 0, sizeof(window->bitmapAllocationBits));
    window->allocatedGlyphCount = FirstGlyphSlot;
    for (int index = FirstGlyphSlot; index < 0x80; ++index) {
        Forward020416c0(&window->glyphs[index]);
        window->glyphReferences[index] = 0;
    }
    window->w1868 = 0;
    window->mode = 0;
    window->b19b2 = 0;
    window->b19b4 = 0;
}
