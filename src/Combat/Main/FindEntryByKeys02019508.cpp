#include <globaldefs.h>
#if defined(jpn)
enum { kNodeOffset = 0x43c };
#else
enum { kNodeOffset = 0x41c };
#endif


struct Entry02019508 {
    unsigned short f0;
    unsigned char pad[0x6e];
};

struct Node02019508 {
    int f0;
    unsigned char pad4[0x10];
    int f14;
    unsigned char pad18[0x2c];
    struct Entry02019508* f44;
    unsigned char pad48[0xc];
    struct Node02019508* f54;
};

struct Base02019508 {
    unsigned char pad0[kNodeOffset];
    struct Node02019508* f41c;
};

// USA: func_02019508
ARM struct Entry02019508* FindEntryByKeys02019508(struct Base02019508* base, int key1, int key2) {
    struct Entry02019508* result;
    struct Node02019508* node;
    result = 0;
    node = base->f41c;
    while (node != 0) {
        if (node->f0 == key1) {
            int count = node->f14;
            struct Entry02019508* e = node->f44;
            int i;
            for (i = 0; i < count; i++, e++) {
                if (e->f0 == key2) {
                    result = e;
                    break;
                }
            }
        }
        node = node->f54;
    }
    return result;
}
