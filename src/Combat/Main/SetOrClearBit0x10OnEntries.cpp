#include <globaldefs.h>

struct BEntry {
    char pad[0x50];
    int field50;
};

struct AEntry {
    char pad[0x14];
    struct BEntry* field14;
};

struct RootEntries {
    char pad[0xc];
    struct AEntry* arr[0x20];
};

// USA: func_0203e5d8
ARM void SetOrClearBit0x10OnEntries_0203e5d8(struct RootEntries* root, int flag) {
    struct AEntry** p = root->arr;
    int i;
    for (i = 0; i < 0x20; i++, p++) {
        struct AEntry* a = *p;
        if (a != 0) {
            struct BEntry* b = a->field14;
            if (b != 0) {
                if (flag) {
                    b->field50 &= ~0x10;
                } else {
                    b->field50 |= 0x10;
                }
            }
        }
    }
}
