#include <globaldefs.h>
#include <std_library_functions.h>

struct CharacterEntry {
    const char* text;
    signed char width;
    signed char length : 6;
    signed char reserved : 1;
    signed char uppercase : 1;
    char padding[2];
};
struct EncodeWorkspace {
    unsigned short command;
    unsigned short commandCopy;
    char buffer[512];
};
struct EncoderCache {
    char pad0[0x800];
    int nextEntry;
};
struct Container02045c00 {
    char pad0[0x1b4];
    EncoderCache cache;
    char pad9b8[0x17b8 - 0x9b8];
    unsigned char usage[0x80];
    char pad1838[0x1e28 - 0x1838];
    char* pairTables;
    inline EncoderCache* GetCache() { return &cache; }
};
typedef Container02045c00 TextEncoder;
extern "C" void __clear(void*, unsigned int);
extern "C" void func_0204483c(TextEncoder*, const char*, char*);
void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);
int Dispatch02044420(void*, void*);
CharacterEntry* FindEntryByKey0204254c(int, int);
int FindEntryIndexByKey020424e4(int, int);
int FindMatchingEntryIndex(Container02045c00*, int);
extern "C" unsigned short func_020459b8(TextEncoder*, int, CharacterEntry*, int);

// USA: func_02045d14
extern "C" ARM unsigned short func_02045d14(TextEncoder* self, const char* text, unsigned short* output, int table) {
    unsigned short count;
    int offset;
    int outIndex;
    int length;
    CharacterEntry* entry;
    EncoderCache* cache;
    EncodeWorkspace work;
    if (text == 0 || output == 0) return 0;
    __clear(work.buffer, sizeof(work.buffer));
    func_0204483c(self, text, work.buffer);
    count = 0;
    offset = 0;
    outIndex = 0;
    if (self->pairTables) RestorePairTables0207df90(self->pairTables);
    while (1) {
        if (outIndex > 0 && output[outIndex - 1] == 0xff01) break;
        memcpy(&work.command, work.buffer + offset, 2);
        if ((work.command & 0xff00) == 0xff00) {
            memcpy(&work.commandCopy, work.buffer + offset, 2);
            output[outIndex] = work.commandCopy;
            offset += 2;
            ++outIndex;
            ++count;
            length = Dispatch02044420(self, &work.commandCopy);
            unsigned int bytes = length * sizeof(unsigned short);
            memcpy(output + outIndex, work.buffer + offset, bytes);
            count += length;
            offset += length * 2;
            outIndex += length;
        } else {
            entry = FindEntryByKey0204254c((int)(work.buffer + offset), table);
            int index = FindEntryIndexByKey020424e4((int)(work.buffer + offset), table);
            if (entry != 0 && index >= 0) {
                int match = FindMatchingEntryIndex(self, (int)entry);
                if (match == -1) {
                    output[outIndex] = func_020459b8(self, index & 0xff, entry, table);
                    cache = self->GetCache();
                    ++cache->nextEntry;
                    cache->nextEntry &= 0x7f;
                } else {
                    unsigned short found = match;
                    output[outIndex] = found;
                    if (self->usage[found] < 0xff) ++self->usage[found];
                }
                offset += entry->length;
            } else {
                output[outIndex] = 0xff19;
                ++offset;
            }
            ++outIndex;
            ++count;
        }
    }
    if (self->pairTables) BackupPairTables0207dfac(self->pairTables);
    return count;
}
