#include <globaldefs.h>
#include "Resource/FontGlyphTable.h"
#include "Resource/FontBankLoader.h"

#if defined(jpn)
extern "C" int func_02042f9c(FontGlyphTable*, const unsigned char*);

// JPN: func_02043014
extern "C" ARM int func_02043014(int pixelSize, unsigned short* encodedCharacter) {
    const unsigned char* key = reinterpret_cast<const unsigned char*>(encodedCharacter);
    if (key == NULL || (signed char)key[0] == 0) return -1;

    int index = func_02042f9c(GetFontGlyphTable_020429bc(pixelSize), key);
    if (index >= 0) return index;
    return func_02042f9c(
        static_cast<FontGlyphTable*>(AlwaysFalse02094b44(GetGlobal02109400_02094a00(), pixelSize)), key)
        | 0x40000000;
}
#endif
