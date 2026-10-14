#include <globaldefs.h>

#if defined(jpn)
#include "std_library_functions.h"

struct CachedTextEntry {
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char references;
    unsigned char unknownf;
};

struct TextOamEntry {
    unsigned int attributes01;
    unsigned short attribute2;
    unsigned short affineParameter;
};

struct CachedTextTable {
    TextOamEntry* drawingBuffer;
    CachedTextEntry entries[96];
    unsigned char unknown604[8];
    unsigned int paletteControl;
    unsigned short nextOamEntry;
};

typedef char CachedTextEntrySizeCheck[sizeof(CachedTextEntry) == 0x10 ? 1 : -1];
typedef char TextOamEntrySizeCheck[sizeof(TextOamEntry) == 8 ? 1 : -1];
typedef char CachedTextEntriesOffsetCheck[offsetof(CachedTextTable, entries) == 4 ? 1 : -1];
typedef char CachedTextPaletteOffsetCheck[offsetof(CachedTextTable, paletteControl) == 0x60c ? 1 : -1];
typedef char CachedTextCursorOffsetCheck[offsetof(CachedTextTable, nextOamEntry) == 0x610 ? 1 : -1];

extern "C" void func_0203bb6c(const CachedTextEntry* entry, TextOamEntry* output,
                              int affineMode, int priority, int affineIndex,
                              int x, int y, int palette);

// JPN indexed-text renderer, corresponding to USA func_0203c4d0.
extern "C" ARM void func_0203c4d0(CachedTextTable* cache, int count, const short* slots,
                                int affineMode, int priority, int affineIndex,
                                int x, int y, int palette, int characterAdvance,
                                int lineHeight) {
    if (slots == NULL || cache->drawingBuffer == NULL) return;
    int textPalette = ((cache->paletteControl >> 5) + palette) & 0xf;
    int penX = x;
    int penY = y;
    for (int i = 0; i < count; ++i) {
        short index = slots[i];
        if (index >= 0) {
            func_0203bb6c(&cache->entries[index],
                         &cache->drawingBuffer[cache->nextOamEntry],
                         affineMode, priority, affineIndex, penX, penY, textPalette);
            ++cache->nextOamEntry;
            cache->nextOamEntry &= 0x7f;
            penX += cache->entries[index].advanceX;
        }
        if (index == -2) {
            penX = x;
            penY += lineHeight;
        } else {
            penX += characterAdvance;
        }
    }
}

#else

struct Source0203c05c {
    char pad[0x22];
    short f22;
};

struct Entry0203c05c {
    unsigned int w;
    unsigned short h;
    unsigned short pad;
};

void BuildPackedEntries0203c05c(struct Source0203c05c* p, struct Entry0203c05c* out,
                                int a3, int a4, int a5, int a6);

struct Sub0203c4d0 {
    unsigned char pad[0xc];
    unsigned int f0c;
    unsigned short f10;
};

struct Obj0203c4d0 {
    struct Entry0203c05c* f0;
    unsigned char pad[0x4fc];
    struct Sub0203c4d0 sub;
};

// USA: func_0203c4d0
extern "C" ARM void func_0203c4d0(void* arg0, short arg1, int arg2, int arg3, int arg4,
                                 int arg5) {
    struct Obj0203c4d0* p = (struct Obj0203c4d0*)arg0;
    int t;

    if (arg1 < 0) {
        return;
    }

    if (p->f0 == 0) {
        return;
    }

    t = (p->sub.f0c >> 5) + arg5;
    t = t & 0xf;

    BuildPackedEntries0203c05c(
        (struct Source0203c05c*)((char*)p + 4 + arg1 * 0x28),
        p->f0 + p->sub.f10,
        arg2, arg3, arg4,
        t & 0xf);

    p->sub.f10 = p->sub.f10 + 4;
    p->sub.f10 = p->sub.f10 & 0x7f;
}
#endif
