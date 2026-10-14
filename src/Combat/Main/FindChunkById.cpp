#include <globaldefs.h>

struct Entry02b0288 {
    unsigned int id;
    unsigned int size;
};
struct Hdr02b0288 {
    unsigned char pad[0xc];
    unsigned short dataOffset;
    unsigned short count;
};

// USA: func_020b0288
ARM struct Entry02b0288 *FindChunkById_020b0288(struct Hdr02b0288 *h, unsigned int key) {
    unsigned char *p = (unsigned char *)h + h->dataOffset;
    unsigned short count = h->count;
    unsigned short i = 0;
    if (count > i) {
        do {
            struct Entry02b0288 *e = (struct Entry02b0288 *)p;
            if (e->id == key) {
                return e;
            }
            p += e->size;
            i++;
        } while (count > i);
    }
    return NULL;
}
