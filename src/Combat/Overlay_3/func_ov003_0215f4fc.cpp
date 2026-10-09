#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_02001aec(const char* a, const char* b, unsigned int n);

struct NamedEntry {
    int id;
    const char* name;
    char pad[0xc];
};

struct NamedEntryTable {
    NamedEntry* entries;
    short field_4;
    short count;
};

struct NamedEntryOwner {
    int field_0;
    NamedEntryTable* table;
};

// USA: func_ov003_0215f4fc
extern "C" ARM NamedEntry* func_ov003_0215f4fc(NamedEntryOwner* self, const char* name) {
    unsigned int len;
    NamedEntry* entry;
    short i;
    short count;
    len = strlen(name);
    count = self->table->count;
    entry = self->table->entries;
    for (i = 0; i < count; i++, entry++) {
        if (entry->name != 0 && func_02001aec(entry->name, name, len) == 0) {
            return entry;
        }
    }
    return 0;
}
