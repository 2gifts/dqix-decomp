#pragma once

#include <globaldefs.h>

struct Entry020429e4 {
    unsigned char first;
    unsigned char second;
};

struct Table020429e4 {
    unsigned short glyphBytes;
    char unknown2[4];
    short glyphCount;
    Entry020429e4* keys;
    char* glyphs;
};

typedef Table020429e4 FontGlyphTable;

FontGlyphTable* GetFontGlyphTable(int pixelSize);
#if defined(jpn)
extern "C" char* func_02043060(FontGlyphTable* table, const unsigned char* encodedCharacter);
#define FindEntryByKeyPair020429e4 func_02043060
#else
char* FindEntryByKeyPair020429e4(FontGlyphTable* table, const unsigned char* encodedCharacter);
#endif
extern "C" char* func_02042a50(int pixelSize, const char* encodedCharacter);
