#include <globaldefs.h>

struct Hdr02b00e0 {
    unsigned short count;
    unsigned short flags;
    unsigned char *base;
};

// USA: func_020b00e0
ARM unsigned char *GetEntryVarStride_020b00e0(struct Hdr02b00e0 *h, unsigned int i) {
    if (i >= h->count) {
        return NULL;
    }
    if (h->flags & 1) {
        return h->base + (i << 4);
    }
    return h->base + (i << 3);
}
