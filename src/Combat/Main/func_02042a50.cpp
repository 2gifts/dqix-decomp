#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Resource/FontGlyphTable.h"

// USA: func_02042a50
extern "C" ARM char* func_02042a50(int pixelSize, const char* encodedCharacter) {
    if (encodedCharacter == NULL) return NULL;
    char* glyph = FindEntryByKeyPair020429e4(GetFontGlyphTable_020429bc(pixelSize),
        reinterpret_cast<const unsigned char*>(encodedCharacter));
    if (glyph != NULL) return glyph;
    return FindEntryByKeyPair020429e4(
        static_cast<FontGlyphTable*>(AlwaysFalse02094b44(GetGlobal02109400_02094a00(), pixelSize)),
        reinterpret_cast<const unsigned char*>(encodedCharacter));
}
