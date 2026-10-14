#include <globaldefs.h>
#include "Resource/FontGlyphTable.h"

#if defined(jpn)
extern "C" void func_02042ea4(unsigned char*, const unsigned char*);

// JPN: func_02042f9c
extern "C" ARM int func_02042f9c(FontGlyphTable* table, const unsigned char* encodedCharacter) {
    if (table == NULL) return -1;
    if (encodedCharacter == NULL || (signed char)encodedCharacter[0] == 0) return -1;

    Entry020429e4 wanted;
    func_02042ea4(reinterpret_cast<unsigned char*>(&wanted), encodedCharacter);
    int count = table->glyphCount;
    Entry020429e4* key = table->keys;
    for (int index = 0; index < count; ++key, ++index) {
        if (wanted.first == key->first && wanted.second == key->second) {
            return index;
        }
    }
    return -1;
}
#endif
