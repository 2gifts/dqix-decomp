#include <globaldefs.h>

struct Entry0xc6b8 {
    char unk0[0x24];
    unsigned char count;
    char unk25[3];
};

struct RefArray0xc6b8 {
    int unk0;
    struct Entry0xc6b8 entries[32];
    char pad[0xE];
    unsigned short total;
};

// USA: func_0203c6b8
ARM void IncrementEntryCount0x24_0203c6b8(struct RefArray0xc6b8* obj, short index) {
    struct Entry0xc6b8* entry;
    unsigned char count;
    if (index < 0) {
        return;
    }
    entry = &obj->entries[index];
    count = entry->count;
    if (count == 0) {
        entry->count = 1;
        obj->total++;
    } else {
        entry->count = count + 1;
    }
}
