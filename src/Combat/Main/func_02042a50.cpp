#include <globaldefs.h>
#include "Resource/FontGlyphTable.h"

extern "C" void* _Z17GetGlobal02109400v(void);
extern "C" void* _Z19AlwaysFalse02094b44v(void*, int);

// USA: func_02042a50
extern "C" ARM char* func_02042a50(int pixelSize, const char* encodedCharacter) {
    if (encodedCharacter == NULL) return NULL;
    char* glyph = FindEntryByKeyPair020429e4(GetFontGlyphTable(pixelSize),
        reinterpret_cast<const unsigned char*>(encodedCharacter));
    if (glyph != NULL) return glyph;
    return FindEntryByKeyPair020429e4(
        static_cast<FontGlyphTable*>(_Z19AlwaysFalse02094b44v(_Z17GetGlobal02109400v(), pixelSize)),
        reinterpret_cast<const unsigned char*>(encodedCharacter));
}
