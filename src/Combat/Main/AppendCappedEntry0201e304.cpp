#include <globaldefs.h>

struct WordTriple0201e304 { unsigned int v[3]; };
struct ByteBlock0201e304 { char v[16]; };
struct WordSix0201e304 { unsigned int v[6]; };

struct Entry0201e304 {
    unsigned int f0;
    struct WordTriple0201e304 g4;
    struct ByteBlock0201e304 a;
    struct ByteBlock0201e304 b;
    struct ByteBlock0201e304 c;
    struct WordSix0201e304 g40;
};

struct Container0201e304 {
    struct Entry0201e304* base;
    int count;
    int capacity;
};

// USA: func_0201e304
extern "C" ARM void _ZN12ZoneFeatures28CreateOpcode64Entry_0201e304ERKNS_13Opcode64EntryE(struct Container0201e304* c, struct Entry0201e304* src) {
    struct Entry0201e304* dst;
    if (c->count >= c->capacity) return;
    dst = &c->base[c->count];
    dst->f0 = src->f0;
    dst->g4 = src->g4;
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->g40 = src->g40;
    c->count++;
}
