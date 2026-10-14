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
struct Reloc020b0278 { char pad[0xc]; unsigned int offset; };

struct Entry02b0288* FindChunkById_020b0288(struct Hdr02b0288* h, unsigned int key);
void RelocateOffsetAt0xc(struct Reloc020b0278* p);

// USA: func_020b01f0
ARM int FindPlttChunkAndRelocate_020b01f0(struct Hdr02b0288* h, void** out) {
    struct Entry02b0288* e = FindChunkById_020b0288(h, 0x504c5454);
    if (e == NULL) {
        *out = NULL;
        return 0;
    }
    RelocateOffsetAt0xc((struct Reloc020b0278*)((char*)e + 8));
    *out = (char*)e + 8;
    return 1;
}
