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
extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);
extern "C" int _Z16Dispatch02044420PvS_(void*, void*);
extern "C" CharacterEntry* _Z22FindEntryByKey0204254cii(int, int);
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int, int);
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
    if (self->pairTables) _Z25RestorePairTables0207df90Pc(self->pairTables);
    while (1) {
        if (outIndex > 0 && output[outIndex - 1] == 0xff01) break;
        memcpy(&work.command, work.buffer + offset, 2);
        if ((work.command & 0xff00) == 0xff00) {
            memcpy(&work.commandCopy, work.buffer + offset, 2);
            output[outIndex] = work.commandCopy;
            offset += 2;
            ++outIndex;
            ++count;
            length = _Z16Dispatch02044420PvS_(self, &work.commandCopy);
            unsigned int bytes = length * sizeof(unsigned short);
            memcpy(output + outIndex, work.buffer + offset, bytes);
            count += length;
            offset += length * 2;
            outIndex += length;
        } else {
            entry = _Z22FindEntryByKey0204254cii((int)(work.buffer + offset), table);
            int index = _Z27FindEntryIndexByKey020424e4ii((int)(work.buffer + offset), table);
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
    if (self->pairTables) _Z24BackupPairTables0207dfacPc(self->pairTables);
    return count;
}
