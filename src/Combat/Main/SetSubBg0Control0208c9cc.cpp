// KEEP-NAME
#include <globaldefs.h>
#include "System/Graphics.h"

// USA: func_0208c9cc
ARM void SetSubBg0Control0208c9cc(int screenSize, int colorMode, int screenBase, int charBase, int extendedPaletteSlot) {
    BG0CNTSUB = (BG0CNTSUB & 0x43) | (screenSize << 14) | (colorMode << 7) |
                (screenBase << 8) | (charBase << 2) | (extendedPaletteSlot << 13);
}
