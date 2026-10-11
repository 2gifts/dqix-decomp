#include <globaldefs.h>

struct Pair0209ab7c { unsigned short a; unsigned short b; };
struct SlotElem0209ab7c {
    unsigned char pad0[0xc];
    struct Pair0209ab7c pairs[17];
};
struct Base0209ab7c {
    unsigned char pad100[0x100];
    struct SlotElem0209ab7c slots[13];
    unsigned char pad510[0xc];
    int counts[16];
};
struct Holder0209ab7c {
    struct Base0209ab7c* base;
};
struct Field150_0209ab7c {
#if defined(jpn)
    unsigned char pad[0x8b8];
#else
    unsigned char pad[0x950];
#endif
    int slot;
};

int GetFieldAt0x150(unsigned char* obj);

// USA: func_0209ab7c
// JPN: func_0209ab7c
extern "C" ARM int func_0209ab7c(struct Holder0209ab7c* h, unsigned char* path, unsigned char* out,
                                 int threshold) {
    if (&h->base->slots[0].pairs[0] == NULL) return 0;
    if (&h->base->counts[0] == NULL) return 0;
    struct Field150_0209ab7c* f = (struct Field150_0209ab7c*)GetFieldAt0x150(path);
    if (f == 0) return 0;
    int slot = f->slot;
    int idx;
    unsigned short a;
    int count = 0;
    for (idx = 0; idx < h->base->counts[slot]; idx++) {
        int lim = *(unsigned short*)((unsigned char*)f + f->slot * 2 + 0x100 + 0x6c);
        int b = h->base->slots[slot].pairs[idx].b;
        a = h->base->slots[slot].pairs[idx].a;
        if (lim >= b) {
            out[count] = (unsigned char)a;
            count++;
        }
    }
    return count;
}
