#include <globaldefs.h>

struct SearchEntry {
    unsigned short key;
    char unk[0xe];
};

struct SearchTable {
    struct SearchEntry* entries;
    int count;
};

// USA: func_02099950
ARM struct SearchEntry* FindEntryByHalfwordKey_02099950(struct SearchTable* table, int key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (key == table->entries[i].key) {
            return &table->entries[i];
        }
    }
    return 0;
}
