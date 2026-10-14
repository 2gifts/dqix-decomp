#include <globaldefs.h>

struct Entry0xc6fc {
#if defined(jpn)
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char count;
    unsigned char unknownf;
#else
    char unk0[0x24];
    unsigned char count;
    char unk25[3];
#endif
};

struct RefArray0xc6fc {
#if defined(jpn)
    void* drawingBuffer;
    Entry0xc6fc entries[96];
    int engine;
    char* bitmapStorage;
    unsigned int paletteControl;
    unsigned short nextOamEntry;
    unsigned short total;
    unsigned char workBuffer[256];
#else
    int unk0;
    struct Entry0xc6fc entries[32];
    char pad[0xE];
    unsigned short total;
#endif
};

// USA: func_0203c6fc
#if defined(jpn)
ARM void DecrementEntryCount0x24(struct RefArray0xc6fc* obj, const short* indices)
#else
ARM void DecrementEntryCount0x24_0203c6fc(struct RefArray0xc6fc* obj, short index)
#endif
{
#if defined(jpn)
    if (indices == NULL) return;
    for (int i = 0; i < 10; ++i) {
        short index = indices[i];
        if (index < 0) continue;
        Entry0xc6fc* entry = &obj->entries[index];
        Entry0xc6fc* next = &obj->entries[index + 1];
        if (entry->count != 0 && next->count != 0) {
            --entry->count;
            --next->count;
            if (entry->count == 0 && next->count == 0) {
                obj->total -= 2;
            }
        }
    }
#else
    struct Entry0xc6fc* entry;
    int count;
    if (index < 0) {
        return;
    }
    entry = &obj->entries[index];
    count = entry->count;
    if (count == 0) {
        return;
    }
    entry->count = count - 1;
    if (((count - 1) & 0xff) == 0) {
        obj->total--;
    }
#endif
}
