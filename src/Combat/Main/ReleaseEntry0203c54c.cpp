#include <globaldefs.h>

#if defined(jpn)
struct CachedGlyphEntryRelease {
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char count;
    unsigned char unknownf;
};

struct CachedGlyphOwnerRelease {
    void* drawingBuffer;
    CachedGlyphEntryRelease entries[96];
    int engine;
    char* bitmapStorage;
    unsigned int paletteControl;
    unsigned short nextOamEntry;
    unsigned short total;
    unsigned char workBuffer[256];
};

extern "C" void func_0203b8e4(char* obj);
#else
void InitStruct0203be8c(char* obj);
#endif

// USA: func_0203c54c
ARM void ReleaseEntry0203c54c(char* obj, short* idxPtr) {
#if defined(jpn)
    if (idxPtr == NULL) return;
    CachedGlyphOwnerRelease* cache = reinterpret_cast<CachedGlyphOwnerRelease*>(obj);
    CachedGlyphEntryRelease* next;
    for (int i = 0; i < 10; ++i) {
        short index = idxPtr[i];
        if (index < 0) continue;
        CachedGlyphEntryRelease* entry = &cache->entries[index];
        next = &cache->entries[index + 1];
        if (entry->count == 0) continue;
        idxPtr[i] = -1;
        --entry->count;
        --next->count;
        if (entry->count != 0) continue;
        func_0203b8e4(reinterpret_cast<char*>(entry));
        func_0203b8e4(reinterpret_cast<char*>(next));
        cache->total -= 2;
    }
#else
    short idx = *idxPtr;
    int cnt;
    char* entry;
    if (idx < 0) return;
    entry = obj + 4 + idx * 0x28;
    *idxPtr = -1;
    cnt = ((unsigned char*)entry)[0x24];
    if (cnt == 0) return;
    cnt = cnt - 1;
    ((unsigned char*)entry)[0x24] = cnt;
    if ((cnt & 0xff) != 0) return;
    InitStruct0203be8c(entry);
    *(unsigned short*)(obj + 0x512) -= 1;
#endif
}
