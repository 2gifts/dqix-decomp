#include <globaldefs.h>
#if defined(jpn)
enum { kOwnerPrefix = 0x43c };
#else
enum { kOwnerPrefix = 0x41c };
#endif


struct Entry02018b34 {
    unsigned short key;
    char pad[0x6e];
};

struct Node02018b34 {
    unsigned int f0;
    char pad4[0x10];
    int count;
    char pad18[0x2c];
    struct Entry02018b34* entries;
    char pad48[0xc];
    struct Node02018b34* next;
};

struct Param02018b34 {
    char pad0[4];
    int f4;
    char pad8[0x24];
    unsigned char nodeId;
    unsigned char entryKey;
};

struct Owner02018b34 {
    char pad0[kOwnerPrefix];
    struct Node02018b34* head;
    char pad420[4];
    int f424;
};

// USA: func_02018b34
ARM struct Entry02018b34* FindEntryByNodeIdAndKey(struct Owner02018b34* owner, struct Param02018b34* p) {
    struct Node02018b34* node;
    struct Entry02018b34* result;
    int count;
    int i;
    if (p->f4 != 2) return NULL;
    if (owner->f424 != 0) return NULL;
    node = owner->head;
    while (node != NULL) {
        if (node->f0 == p->nodeId) break;
        node = node->next;
    }
    result = NULL;
    if (node == NULL) return result;
    count = node->count;
    for (i = 0; i < count; i++) {
        if (p->entryKey == node->entries[i].key) {
            result = &node->entries[i];
            break;
        }
    }
    return result;
}
