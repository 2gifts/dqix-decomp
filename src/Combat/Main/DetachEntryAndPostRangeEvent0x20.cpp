#include <globaldefs.h>

struct SlotArray020d2eb8;
void StoreField0x3cArrayEntryAndFlush(struct SlotArray020d2eb8*, int, int);
void* ResolveOffsetOrPointerEntry_020d2eec(void*, int);
void PostEvent0x20_020d20c4(int, int);

// USA: func_020be4f4
ARM void DetachEntryAndPostRangeEvent0x20_020be4f4(int start, int length, void* base, int index) {
    if (start == (int)ResolveOffsetOrPointerEntry_020d2eec(base, index)) {
        StoreField0x3cArrayEntryAndFlush((struct SlotArray020d2eb8*)base, index, 0);
    }
    PostEvent0x20_020d20c4(start, start + length);
}
