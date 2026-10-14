#include <globaldefs.h>

struct Holder020bd5e4 { char _pad[0x8c]; unsigned char* base; };
extern struct Holder020bd5e4* data_02110370;

struct OffsetTable020bd5e4 { int count; int offsets[1]; };

// USA: func_020bd5e4
ARM void* GetOffsetEntry0x24_020bd5e4(int index) {
    unsigned char* p = data_02110370->base;
    int rel = *(int*)(p + 0x24);
    p = (rel == 0) ? 0 : p + rel;
    if (p == 0) return 0;
    if (index < 0) return 0;
    struct OffsetTable020bd5e4* table = (struct OffsetTable020bd5e4*)p;
    if ((unsigned int)index >= (unsigned int)table->count) return 0;
    int entryRel = table->offsets[index];
    unsigned char* baseFinal = *(unsigned char**)((char*)data_02110370 + 0x8c);
    return entryRel == 0 ? 0 : baseFinal + entryRel;
}
