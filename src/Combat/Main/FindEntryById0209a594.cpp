#include <globaldefs.h>

struct Entry0209a594 {
    #if defined(jpn)
    unsigned short id : 12;
    unsigned short otherFlags : 4;
#else
    unsigned short id : 11;
    unsigned short otherFlags : 5;
#endif
    char rest[10];
};

struct Table0209a594 {
    struct Entry0209a594* entries;
    int count;
};

// USA: func_0209a594  (semantic: FindEntryById0209a594)
extern "C" ARM struct Entry0209a594* func_0209a594(struct Table0209a594* self, int id) {
    int i;
    struct Entry0209a594* table = self->entries;
    if (table == 0) return 0;
    if (id >= 0x11f) return 0;
    if (table[id].id == id) {
        return &table[id];
    }
    for (i = 0; i < self->count; i++) {
        if (table[i].id == id) {
            return &table[i];
        }
    }
    return 0;
}
