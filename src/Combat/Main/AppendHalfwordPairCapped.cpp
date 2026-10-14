#include <globaldefs.h>

struct HalfwordPair {
    unsigned short a;
    unsigned short b;
};

struct BoundedHalfwordPairList {
    char pad[0x24];
    unsigned char capacity;
    unsigned char count;
    char pad2[2];
    struct HalfwordPair* entries;
};

// USA: func_02028378
ARM void AppendHalfwordPairCapped_02028378(struct BoundedHalfwordPairList* list, struct HalfwordPair* src) {
    struct HalfwordPair* entries = list->entries;
    struct HalfwordPair* dst;
    if (entries == 0) {
        return;
    }
    if (list->capacity <= list->count) {
        return;
    }
    dst = &entries[list->count];
    dst->a = src->a;
    dst->b = src->b;
    list->count++;
}
