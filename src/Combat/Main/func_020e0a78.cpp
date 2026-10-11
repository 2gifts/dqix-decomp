#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct FlagWord02046708;

struct CombatResBuildView {
    unsigned char unknown0[0x76c];
    SafeAllocator *allocator;
    void *sourceData;
    unsigned int size;
};

extern "C" void *_Z27GetDataPtr02114e04_020d6c00v();
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(FlagWord02046708 *flags, unsigned int mask);
extern "C" void VectorizedInvertedMemcpy(void *dst, void *src, unsigned int size);
extern "C" void _Z29SetupWeightedEntriesAndSubmitPvii(void *obj, void *buf, int offset, int dead_r3);
extern "C" void _Z41SetupWeightedEntriesAndSubmitPair020e0cfcPvii(void *obj, void *buf, int offset, int dead_r3);
extern "C" void func_020e0b4c(void *obj, void *buf, int offset, int dead_r3);
extern "C" void func_020e0ec4(void *obj, void *buf, int offset, int dead_r3);
void DelayThenSyncBit0();
void CleanInvalidateCacheRange(const void *addr, unsigned int size);
extern "C" int LoadToSubObjVRAM(void *dst, int mode, unsigned int size);

// USA: func_020e0a78
extern "C" ARM int func_020e0a78(void *receiver) {
    CombatResBuildView *state = static_cast<CombatResBuildView *>(receiver);

    if (state->allocator == 0) {
        return 0;
    }
    if (_Z17TestFlags02046708P16FlagWord02046708j(static_cast<FlagWord02046708 *>(_Z27GetDataPtr02114e04_020d6c00v()), 0x41)) {
        return 0;
    }

    void *buf = state->allocator->Allocate(state->size);
    VectorizedInvertedMemcpy(state->sourceData, buf, state->size);
    _Z29SetupWeightedEntriesAndSubmitPvii(receiver, buf, 0, 0x700);
    func_020e0b4c(receiver, buf, 0x700, 0xfc0);
    func_020e0ec4(receiver, buf, 0x16c0, 0x9c0);
    _Z41SetupWeightedEntriesAndSubmitPair020e0cfcPvii(receiver, buf, 0x2080, 0xd00);
    DelayThenSyncBit0();
    CleanInvalidateCacheRange(buf, state->size);
    LoadToSubObjVRAM(buf, 0, state->size);
    state->allocator->Free(buf);

    return 1;
}
