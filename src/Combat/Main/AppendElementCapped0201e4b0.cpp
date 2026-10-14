#include <globaldefs.h>

struct Inner0201e4b0 {
    unsigned int v[6];
};

struct Pair0201e4b0 {
    unsigned int v[2];
};

struct Elem0201e4b0 {
    struct Inner0201e4b0 blk;
    struct Pair0201e4b0 mid;
    short f20;
};

struct List0201e4b0 {
    char unk[0xc];
    struct Elem0201e4b0* data;
    int count;
    int capacity;
};

// USA: func_0201e4b0
extern "C" ARM void _ZN12ZoneFeatures28CreateOpcode66Entry_0201e4b0ERKNS_13Opcode66EntryE(struct List0201e4b0* list, struct Elem0201e4b0* src) {
    int count = list->count;
    struct Elem0201e4b0* dst;
    if (count >= list->capacity) {
        return;
    }
    dst = &list->data[count];
    dst->blk = src->blk;
    dst->mid = src->mid;
    dst->f20 = src->f20;
    list->count++;
}
