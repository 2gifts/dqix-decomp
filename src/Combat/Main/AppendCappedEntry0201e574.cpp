#include <globaldefs.h>

struct WordSix0201e574 { unsigned int v[6]; };
struct WordTwelve0201e574 { unsigned int v[12]; };
struct WordTriple0201e574 { unsigned int v[3]; };
struct WordPair0201e574 { unsigned int v[2]; };

struct Entry0201e574 {
    unsigned int f0;
    struct WordSix0201e574 g4;
    unsigned int f1c;
    struct WordTwelve0201e574 g20;
    short f50;
    short f52;
    unsigned int f54;
    struct WordTriple0201e574 g58;
    struct WordPair0201e574 g64;
    unsigned int f6c;
};

struct Container0201e574 {
    char pad0[0x18];
    struct Entry0201e574* base;
    int count;
    int capacity;
};

// USA: func_0201e574
extern "C" ARM void _ZN12ZoneFeatures28CreateOpcode68Entry_0201e574ERKNS_13Opcode68EntryE(struct Container0201e574* c, struct Entry0201e574* src) {
    struct Entry0201e574* dst;
    if (c->count >= c->capacity) return;
    dst = &c->base[c->count];
    dst->f0 = src->f0;
    dst->g4 = src->g4;
    dst->f1c = src->f1c;
    dst->g20 = src->g20;
    dst->f50 = src->f50;
    dst->f52 = src->f52;
    dst->f54 = src->f54;
    dst->g58 = src->g58;
    dst->g64 = src->g64;
    dst->f6c = src->f6c;
    c->count++;
}
