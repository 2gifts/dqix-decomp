#include <globaldefs.h>
#include "Resource/FontGlyphTable.h"

#if defined(jpn)
extern "C" void func_02042ea4(unsigned char*, const unsigned char*);
#endif

// USA: func_020429e4
ARM char* FindEntryByKeyPair020429e4(FontGlyphTable* table, const unsigned char* encodedCharacter) {
    if (table == NULL) return NULL;
    Entry020429e4 wanted;
#if defined(jpn)
    func_02042ea4(reinterpret_cast<unsigned char*>(&wanted), encodedCharacter);
#else
    if (encodedCharacter == NULL) {
        wanted.first = 0;
        wanted.second = 0;
    } else {
        wanted.first = encodedCharacter[0];
        wanted.second = encodedCharacter[1];
    }
#endif
    int count = table->glyphCount;
    Entry020429e4* key = table->keys;
    for (int index = 0; index < count; ++key, ++index) {
        if (wanted.first == key->first && wanted.second == key->second) {
            return table->glyphs + index * table->glyphBytes;
        }
    }
    return NULL;
}
