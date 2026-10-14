#include <globaldefs.h>

struct AppendEntry {
    int a;
    int b;
};

struct AppendPairList {
    unsigned char b0;
    unsigned char capacity;
    unsigned char b2;
    unsigned char count;
    int w4;
    struct AppendEntry* entries;
};

// USA: func_020281d8
ARM void AppendPairToBoundedList_020281d8(struct AppendPairList* list, struct AppendEntry* src) {
    struct AppendEntry* dst;
    if (list->capacity <= list->count) {
        return;
    }
    dst = &list->entries[list->count];
    dst->a = src->a;
    dst->b = src->b;
    list->count++;
}
