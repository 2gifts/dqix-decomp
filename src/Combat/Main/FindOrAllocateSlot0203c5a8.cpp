#include <globaldefs.h>

extern "C" void __clear(void* buf, int size);
extern "C" int func_020426bc(void* src, void* buf, int flag);
extern "C" int func_02001aec(void* entry, void* param1, int category);
extern "C" void func_0203bebc(void* entry, void* buf, void* dest);

struct Entry0203c5a8 {
    char pad[0x20];
    unsigned char category;
    char pad2[3];
    unsigned char inUse;
    char pad3[3];
};

// USA: func_0203c5a8  (semantic: FindOrAllocateSlot0203c5a8)
#if defined(jpn)
struct CachedGlyphEntry {
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char references;
    unsigned char unknownf;
};

struct CachedGlyphTablePrefix {
    void* drawingBuffer;
    CachedGlyphEntry entries[96];
    int engine;
    char* bitmapStorage;
    unsigned int paletteControl;
    unsigned short nextOamEntry;
    unsigned short allocatedEntries;
};

extern "C" int func_02043014(int, unsigned short*);
extern "C" char* func_02043110(int, int);
extern "C" void func_0203b914(CachedGlyphEntry*, int, char*, char**, int, void*);
#endif

#if defined(jpn)
extern "C" ARM void func_0203c5a8(void* self, void* param1, void* output, int characterAdvance)
#else
extern "C" ARM void func_0203c5a8(void* self, void* param1, short* outIndex)
#endif
{
#if defined(jpn)
    CachedGlyphTablePrefix* cache = static_cast<CachedGlyphTablePrefix*>(self);
    char* text = static_cast<char*>(param1);
    short* slots = static_cast<short*>(output);
    if (text == NULL || slots == NULL) return;

    for (short position = 0; position < 20; position += 3) {
        if (text[position] == 0) break;
        char key[7];
        __clear(key, 7);
        key[0] = text[position];
        key[1] = text[position + 1];
        if (text[position + 2] != 0) {
            key[2] = text[position + 2];
            key[3] = text[position + 3];
            if (text[position + 4] != 0) {
                key[4] = text[position + 4];
                key[5] = text[position + 5];
            }
        }
        int first = func_02043014(10, reinterpret_cast<unsigned short*>(key));
        int second = func_02043014(10, reinterpret_cast<unsigned short*>(key + 2));
        int third = func_02043014(10, reinterpret_cast<unsigned short*>(key + 4));
        if (first == -1 && second == -1 && third == -1) {
            position += 3;
            continue;
        }
        if (first == -1) {
            text[position] = text[position + 1] = 0;
        }
        if (second == -1) {
            text[position + 2] = text[position + 3] = 0;
        }
        if (third == -1) {
            text[position + 4] = text[position + 5] = 0;
        }

        short index;
        int checked = 0;
        bool needsAllocation = true;
        for (index = 0; index < 95; index += 2) {
            CachedGlyphEntry* entry = &cache->entries[index];
            CachedGlyphEntry* next = &cache->entries[index + 1];
            if (entry->references != 0 &&
                entry->text[0] == text[position] && entry->text[1] == text[position + 1] &&
                entry->text[2] == text[position + 2] && entry->text[3] == text[position + 3] &&
                entry->text[4] == text[position + 4] && entry->text[5] == text[position + 5] &&
                characterAdvance == entry->advanceX) {
                ++entry->references;
                ++next->references;
                slots[position / 3] = index;
                needsAllocation = false;
                break;
            }
            if (cache->allocatedEntries == ++checked) break;
        }

        if (needsAllocation) {
            for (index = 0; index < 95; ++index) {
                CachedGlyphEntry* entry = &cache->entries[index];
                CachedGlyphEntry* next = &cache->entries[index + 1];
                if (entry->references == 0 && next->references == 0) {
                    char* glyphs[3];
                    __clear(glyphs, 12);
                    glyphs[0] = func_02043110(10, first);
                    glyphs[1] = func_02043110(10, second);
                    glyphs[2] = func_02043110(10, third);
                    func_0203b914(entry, cache->engine, text + position, glyphs,
                        characterAdvance, cache->bitmapStorage + index * 128);
                    cache->allocatedEntries += 2;
                    entry->references = 1;
                    next->references = 1;
                    slots[position / 3] = index;
                    break;
                }
            }
        }
        position += 3;
    }
#else
    if (param1 == 0) return;
    char buf[0x100];
    __clear(buf, 0x100);
    int category = func_020426bc(param1, buf, 0);

    struct Entry0203c5a8* entry = (struct Entry0203c5a8*)((char*)self + 4);
    for (short i = 0; i < 0x20; entry = (struct Entry0203c5a8*)((char*)entry + 0x28), i++) {
        if (entry->inUse != 0 && entry->category == category) {
            if (func_02001aec(entry, buf, category) == 0) {
                entry->inUse = entry->inUse + 1;
                *outIndex = i;
                return;
            }
        }
    }

    entry = (struct Entry0203c5a8*)((char*)self + 4);
    for (short j = 0; j < 0x20; entry = (struct Entry0203c5a8*)((char*)entry + 0x28), j++) {
        if (entry->inUse == 0) {
            unsigned short counter = *(unsigned short*)((char*)self + 0x512);
            void* table = *(void**)((char*)self + 0x508);
            counter = counter + 1;
            *(unsigned short*)((char*)self + 0x512) = counter;
            entry->inUse = 1;
            entry->category = (unsigned char)category;
            func_0203bebc(entry, buf, (char*)table + j * 0x400);
            *outIndex = j;
            return;
        }
    }
#endif
}
