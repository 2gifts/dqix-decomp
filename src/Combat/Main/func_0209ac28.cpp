#include <globaldefs.h>

struct Pair0209ac28 { unsigned short a; unsigned short b; };
struct SlotElem0209ac28 {
    unsigned char pad0[0xc];
    struct Pair0209ac28 pairs[17];
};
struct Base0209ac28 {
    unsigned char pad100[0x100];
    struct SlotElem0209ac28 slots[13];
    unsigned char pad510[0xc];
    int counts[16];
};
struct Holder0209ac28 {
    struct Base0209ac28* base;
};
struct Field150_0209ac28 {
#if defined(jpn)
    unsigned char pad[0x8b8];
#else
    unsigned char pad[0x950];
#endif
    int slot;
};

int GetFieldAt0x150(unsigned char* obj);

// USA: func_0209ac28
// JPN: func_0209ac28
extern "C" ARM int func_0209ac28(struct Holder0209ac28* h, unsigned char* path, int key) {
    if (&h->base->slots[0].pairs[0] == NULL) return 0;
    if (&h->base->counts[0] == NULL) return 0;
    struct Field150_0209ac28* f = (struct Field150_0209ac28*)GetFieldAt0x150(path);
    if (f == 0) return 0;
    int slot = f->slot & 0xff;
    int lim = *(unsigned short*)((unsigned char*)f + slot * 2 + 0x100 + 0x6c) & 0xff;
    int idx;
    for (idx = 0; idx < h->base->counts[slot]; idx++) {
        if (h->base->slots[slot].pairs[idx].a == key) {
            return h->base->slots[slot].pairs[idx].b <= lim;
        }
    }
    return 0;
}
