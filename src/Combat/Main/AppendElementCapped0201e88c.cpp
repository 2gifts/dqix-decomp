#include <globaldefs.h>

struct Vec0201e88c {
    int v[3];
};

struct Elem0201e88c {
    struct Vec0201e88c a;
    struct Vec0201e88c b;
    short f18;
    int f1c;
    int f20;
    int f24;
    int f28;
};

struct Container0201e88c {
    char unk[0x80];
    unsigned short count;
    unsigned short pad82;
    struct Elem0201e88c* base;
};

// USA: func_0201e88c
extern "C" ARM void _ZN12ZoneFeatures28CreateOpcode7bEntry_0201e88cERKNS_13Opcode7bEntryE(struct Container0201e88c* c, struct Elem0201e88c* src) {
    unsigned short count;
    struct Elem0201e88c* dst;
    if (c->base == NULL) {
        return;
    }
    count = c->count;
    c->count = count + 1;
    dst = &c->base[count];
    dst->a = src->a;
    dst->b = src->b;
    dst->f18 = src->f18;
    dst->f1c = src->f1c;
    dst->f20 = src->f20;
    dst->f24 = src->f24;
    dst->f28 = src->f28;
}
