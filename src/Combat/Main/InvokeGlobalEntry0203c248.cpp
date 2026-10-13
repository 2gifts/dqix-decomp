#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
struct CachedTextEntry {
    short fontPixelSize;
    short tileIndex;
    char text[10];
    unsigned char references;
    unsigned char unknownf;
};
struct CachedTextTable {
    void* drawingBuffer;
    CachedTextEntry entries[96];
};
#else
struct CachedTextEntry {
    unsigned char glyphIndices[32];
    unsigned char unknown20[8];
};
struct CachedTextTable {
    void* drawingBuffer;
    CachedTextEntry entries[32];
};
#endif

extern CachedTextTable* data_02105244;
int StringLength(const char* text);
extern "C" void func_02042764(const unsigned char* glyphIndices, char* output, int fontIndex);

#if defined(jpn)
// USA: func_0203c248
extern "C" ARM void func_0203bdf4(const short* textSlots, char* output) {
    CachedTextTable* cache = data_02105244;
    if (cache == NULL) return;
    CachedTextEntry* entries;
    int used = 0;
    entries = cache->entries;

    for (int slot = 0; slot < 10; ++slot) {
        short index = textSlots[slot];
        if (index >= 0) {
            CachedTextEntry* entry = &entries[index];
            int length = StringLength(entry->text);
            memcpy(output + used, entry->text, length);
            used += length;
            ++slot;
        }
    }
}
#else
// USA: func_0203c248
ARM void InvokeGlobalEntry0203c248(char* object, int destination) {
    CachedTextTable* cache = data_02105244;
    CachedTextEntry* entries;
    short index;
    if (cache == NULL) return;
    entries = cache->entries;
    index = *reinterpret_cast<short*>(object + 0x14);
    if (index < 0) return;
    func_02042764(entries[index].glyphIndices, reinterpret_cast<char*>(destination), 0);
}
#endif
