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

struct Entry02b0288 *FindChunkById_020b0288(struct Hdr02b0288 *h, unsigned int key);

struct Reloc020b0268 { char pad[0x4]; unsigned int offset; };
void RelocateOffsetAt0x4(struct Reloc020b0268* p);

// USA: func_020b022c
ARM int FindPcmpChunk_020b022c(struct Hdr02b0288* h, void** out) {
    struct Entry02b0288* entry = FindChunkById_020b0288(h, 0x50434d50);
    if (entry == NULL) {
        *out = NULL;
        return 0;
    }
    RelocateOffsetAt0x4((struct Reloc020b0268*)((char*)entry + 8));
    *out = (char*)entry + 8;
    return 1;
}
