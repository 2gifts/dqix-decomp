#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define ResetAllocatorAndCallInner02154da8 func_ov005_02156408
enum { kSlotCollection = 0x1964 };
#else
enum { kSlotCollection = 0x19ec };
#endif

struct PackedSlot;
struct SlotHeader;
struct SlotCollection {
    PackedSlot* entries;
    unsigned short count;
    unsigned short used;
};

struct Mid02154da8 {
    char unknown0[0x26c];
    SafeAllocator allocator;
    char unknownAfterAllocator[kSlotCollection - 0x280];
    SlotCollection slots;
};

extern "C" void func_ov023_021dad78(SlotCollection* slots);
extern "C" void func_ov023_021dad8c(SlotCollection* slots, SafeAllocator* allocator, SlotHeader* source, void* context);

// USA: func_ov005_02154da8
#if defined(jpn)
extern "C"
#endif
ARM void ResetAllocatorAndCallInner02154da8(Mid02154da8* menu, int sourceAddress, int contextAddress) {
    SafeAllocator* allocator = &menu->allocator;
    allocator->Reset();
    func_ov023_021dad78(&menu->slots);
    func_ov023_021dad8c(&menu->slots, allocator, (SlotHeader*)sourceAddress, (void*)contextAddress);
}
