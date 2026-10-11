#include <globaldefs.h>

#if defined(jpn)
enum { slotArrayOffset = 0x9cc };
#else
enum { slotArrayOffset = 0xa98 };
#endif

struct Elem02027b5c {
    unsigned short h0;
    unsigned char b2;
    int w4;
    int w8;
};

struct Container02027b5c {
    char pad[slotArrayOffset];
    unsigned char capacity;
    unsigned char count;
    char pad2[2];
    struct Elem02027b5c* base;
};

// USA: func_02027b5c
ARM void AppendCappedElement02027b5c(struct Container02027b5c* c, unsigned short h, unsigned char b, int w4, int w8) {
    struct Elem02027b5c* base = c->base;
    struct Elem02027b5c* dst;
    if (base == NULL) return;
    if (c->capacity <= c->count) return;
    dst = &base[c->count];
    dst->h0 = h;
    dst->b2 = b;
    dst->w4 = w4;
    dst->w8 = w8;
    c->count++;
}
