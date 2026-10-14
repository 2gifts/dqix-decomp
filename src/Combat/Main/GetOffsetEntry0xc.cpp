#include <globaldefs.h>

struct Holder020bd4b8 { char _pad[0x8c]; unsigned char* base; };
extern struct Holder020bd4b8* data_02110370;

struct OffsetTable020bd4b8 { int count; int offsets[1]; };

// USA: func_020bd4b8
ARM void* GetOffsetEntry0xc_020bd4b8(int index) {
    unsigned char* p = data_02110370->base;
    int rel = *(int*)(p + 0xc);
    p = (rel == 0) ? 0 : p + rel;
    if (p == 0) return 0;
    if (index < 0) return 0;
    struct OffsetTable020bd4b8* table = (struct OffsetTable020bd4b8*)p;
    if ((unsigned int)index >= (unsigned int)table->count) return 0;
    int entryRel = table->offsets[index];
    unsigned char* baseFinal = *(unsigned char**)((char*)data_02110370 + 0x8c);
    return entryRel == 0 ? 0 : baseFinal + entryRel;
}
