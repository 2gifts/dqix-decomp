#include <globaldefs.h>
#if defined(jpn)
enum { kCountOffset = 0x497 };
#else
enum { kCountOffset = 0x477 };
#endif

#include "World/LootableContainer.h"


struct ElementSlot02015a2c {
    char pad[0x16];
    unsigned char flag;
    char pad2[0x24 - 0x17];
};

struct Something02015a2c {
    char pad0[0x8];
    int field8;
    char pad1[kCountOffset - 0xc];
    unsigned char count;
    char pad2[0x47c - 0x478];
    struct ElementSlot02015a2c* arr;
};

// USA: func_02015a2c
ARM int CheckSlotsForFlagState02015a2c(struct Something02015a2c* obj) {
    int i;
    if (!(int)LootableContainerManager::GetMainInstance()) return 0;
    if (!obj->field8) return 0;
    for (i = 0; i < obj->count; i++) {
        unsigned char f = obj->arr[i].flag;
        if (f != 0 && f != 1 && f != 8) return 1;
    }
    return 0;
}
