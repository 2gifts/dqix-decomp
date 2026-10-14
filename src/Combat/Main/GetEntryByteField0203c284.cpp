#include <globaldefs.h>

#if defined(jpn)
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
struct Struct0203c1c8 {
    short textSlots[10];
    int x;
    int y;
    int lineHeight;
    int characterAdvance;
    int paletteOffset;
    int alignment;
    int priority;
    int affineIndex;
    int affineMode;
};
extern CachedTextTable* data_02105244;
int StringLength(const char* text);

ARM int GetEntryByteField0203c284(const Struct0203c1c8* text) {
    CachedTextTable* cache = data_02105244;
    if (cache == NULL) return 0;
    CachedTextEntry* entries;
    int cells = 0;
    entries = cache->entries;
    for (int slot = 0; slot < 10; ++slot) {
        short index = text->textSlots[slot];
        if (index >= 0) ++cells;
        int length = StringLength(entries[index].text);
        switch (length) {
            case 2: ++slot; break;
            case 4: ++slot; ++cells; break;
            case 6: ++slot; cells += 2; break;
        }
    }
    return cells * text->characterAdvance;
}
#else

extern void* data_02105244;

struct Entry0203c284 {
    char pad[0x21];
    unsigned char field21;
    char pad2[6];
};

// USA: func_0203c284
ARM unsigned char GetEntryByteField0203c284(char* obj) {
    char* data = (char*)data_02105244;
    if (data == NULL) return 0;
    {
        struct Entry0203c284* arr = (struct Entry0203c284*)(data + 4);
        short idx = *(short*)(obj + 0x14);
        if (idx < 0) return 0;
        return arr[idx].field21;
    }
}

#endif
