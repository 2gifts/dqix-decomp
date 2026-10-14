#include <globaldefs.h>

struct Reloc020b01e0;
void RelocateOffsetAt0x14(struct Reloc020b01e0*);

struct Hdr02b0288;
struct Entry02b0288;
struct Entry02b0288* FindChunkById_020b0288(struct Hdr02b0288*, unsigned int);

// USA: func_020b01a4
ARM int GetCharBlock_020b01a4(void* file, void** out) {
    struct Entry02b0288* chunk = FindChunkById_020b0288((struct Hdr02b0288*)file, 0x43484152);
    if (chunk == 0) {
        *out = 0;
        return 0;
    }
    RelocateOffsetAt0x14((struct Reloc020b01e0*)((char*)chunk + 8));
    *out = (char*)chunk + 8;
    return 1;
}
