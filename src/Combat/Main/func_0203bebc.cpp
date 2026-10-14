#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct02020520 {
    int a;
    short b;
    short c;
    short d;
    short e;
};

struct S_b20c {
    int field0;
    int field4;
    unsigned char field8;
};

struct Glyph020425b4 {
    int pad;
    signed char width;
};

void ClearTwoWordsAndByte_0205b20c(struct S_b20c* obj);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);
void* GetGlobalField0x1c020421a0(void);
void* GetBoundedEntry020425b4(int idx, int tableIdx);
int LookupKeyValue020425e4(int a, int b, int tableIdx);
int GetWordFromTable02042648(int idx);
void CleanInvalidateCacheRange(const void* p, unsigned int len);
extern "C" void LoadToSubObjVRAM(const void* data, unsigned int offset, unsigned int length);
extern "C" int func_0205b36c(void* self, void* glyph, short a, int b, unsigned char c, unsigned char d);

#if defined(jpn)
#include "Resource/FontGlyphTable.h"
#include "System/Graphics.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"

struct CachedGlyphEntry0203bebc {
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char references;
    unsigned char unknownf;
};

struct CachedGlyphOwner0203bebc {
    void* drawingBuffer;
    CachedGlyphEntry0203bebc entries[96];
    int engine;
    char* bitmapStorage;
    unsigned int paletteControl;
    unsigned short nextOamEntry;
    unsigned short allocatedEntries;
    unsigned char workBuffer[256];
};

struct GlyphTileOffsets0203bebc {
    unsigned int offsets[8];
};

extern CachedGlyphOwner0203bebc* data_02105244;
extern const GlyphTileOffsets0203bebc data_020e8200;
extern "C" void __clear(void*, int);
#endif

// USA: func_0203bebc
#if defined(jpn)
extern "C" ARM void func_0203bebc(void* rawEntry, int engine, char* text, char** glyphs,
                                int characterAdvance, void* dest)
#else
extern "C" ARM void func_0203bebc(void* entry, void* buf, void* dest)
#endif
{
#if defined(jpn)
    CachedGlyphEntry0203bebc* entry = static_cast<CachedGlyphEntry0203bebc*>(rawEntry);
    if (text == NULL) return;
    memset(entry->text, 0, 10);
    memcpy(entry->text, text, 6);
    entry->text[6] = 0;

    switch (DISPCNTSUB & 0x300010) {
    case 0x10:
        entry->tileIndex = (unsigned int)dest >> 5;
        break;
    case 0x100010:
        entry->tileIndex = (unsigned int)dest >> 6;
        break;
    case 0x200010:
        entry->tileIndex = (unsigned int)dest >> 7;
        break;
    }
    entry->advanceX = characterAdvance;
    FontGlyphTable* font = GetFontGlyphTable_020429bc(10);
    if (font == NULL) return;
    int height = font->glyphHeight;
    unsigned char raster[256];
    __clear(raster, 256);
    for (unsigned char glyph = 0; glyph < 3; ++glyph) {
        unsigned char bit = 0;
        const unsigned char* bitmap = reinterpret_cast<const unsigned char*>(glyphs[glyph]);
        if (bitmap == NULL) continue;
        unsigned char* row = raster + glyph * 5;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < 10; ++x) {
                if (*bitmap & (1 << bit)) {
                    if (x & 1) {
                        row[x >> 1] = (row[x >> 1] & 0xf) | 0xf0;
                    } else {
                        row[x >> 1] &= 0xf0;
                        row[x >> 1] |= 0xf;
                    }
                }
                ++bit;
                if (bit >= 8) {
                    bit = 0;
                    ++bitmap;
                }
            }
            row += 16;
        }
    }

    unsigned int rowOffset;
    unsigned int outputOffset;
    unsigned int tile;
    unsigned int tileRow;
    unsigned char* const work = data_02105244->workBuffer;
    memset(work, 0, 256);
    GlyphTileOffsets0203bebc offsets = data_020e8200;
    outputOffset = 0;
    for (tile = 0; tile < 8; ++tile) {
        rowOffset = 0;
        for (tileRow = 0; tileRow < 8; ++tileRow) {
            memcpy(work + outputOffset, raster + offsets.offsets[tile] + rowOffset, 4);
            rowOffset += 16;
            outputOffset += 4;
        }
    }
    CleanInvalidateCacheRange(work, 256);
    if (engine == 0) {
        LoadToMainObjVRAM(work, (unsigned int)dest, 256);
    } else if (engine == 1) {
        LoadToSubObjVRAM(work, (unsigned int)dest, 256);
    }
#else
    int limit;
    char* g = (char*)GetGlobalField0x1c020421a0();
    void* fp = *(void**)(g + 0x60);
    memset(fp, 0, 0x400);

    struct Struct02020520 arr[4];
    int off = 0;
    int acc = 0;
    for (int i = 0; i < 4; i++) {
        struct Struct02020520* e = &arr[i];
        e->a = off;
        e->b = acc;
        e->c = 0;
        e->d = 0x20;
        e->e = 0x10;
        off += 0x100;
        acc += e->d;
    }

    struct S_b20c localObj;
    ClearTwoWordsAndByte_0205b20c(&localObj);
    SetField0_0205b220(&localObj, (int)fp);
    SetFieldsAt0x4And0x8_0205b228(&localObj, (int)arr, 4);

    *(short*)((char*)entry + 0x22) = (short)((unsigned int)dest >> 7);
    memset(entry, 0, 0x20);
    memcpy(entry, buf, ((unsigned char*)entry)[0x20]);

    int total = 0;
    limit = ((unsigned char*)entry)[0x20];
    int prev = 0xff;
    int font = GetWordFromTable02042648(0);
    unsigned char ch;
    int cnt = 0;
    unsigned char* p = (unsigned char*)buf;
    for (; cnt < limit; cnt++) {
        ch = *p;
        if (ch == 0) break;
        int c = font;
        struct Glyph020425b4* gl = (struct Glyph020425b4*)GetBoundedEntry020425b4(ch, 0);
        if (gl != 0) {
            c = gl->width;
            func_0205b36c(&localObj, gl, (short)total, 0, 0xf, 0);
        }
        int w = total + LookupKeyValue020425e4(prev, ch, 0);
        total = w + (c + 1);
        prev = ch;
        p++;
    }

    CleanInvalidateCacheRange(fp, 0x400);
    LoadToSubObjVRAM(fp, (unsigned int)dest, 0x400);
    ((unsigned char*)entry)[0x21] = total - 1;
#endif
}
