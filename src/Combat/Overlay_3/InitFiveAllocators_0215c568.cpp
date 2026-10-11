#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue4000_3000 = 0x3000 };
enum { kRegionValue7C_94 = 0x94 };
enum { kRegionValue5C_28 = 0x28 };
#else
enum { kRegionValue4000_3000 = 0x4000 };
enum { kRegionValue7C_94 = 0x7c };
enum { kRegionValue5C_28 = 0x5c };
#endif


extern "C" void func_020c9be0(void);
int GetGlobalField0x1c020421a0(void);

// func_ov017_021bacd8 supplies state storage allocated from the same backing
// allocator. Each embedded allocator receives a separate arena buffer.
// The purpose of the final copied global field is not established here.
// USA: func_ov003_0215c568
// JPN: func_ov003_0215d87c
extern "C" ARM void func_ov003_0215c568(void* allocatorState, SafeAllocator* backingAllocator) {
    if (backingAllocator == 0) return;

    void* arenaBuffer = backingAllocator->Allocate(0x2000);
    if (arenaBuffer == 0) func_020c9be0();
    ((SafeAllocator*)allocatorState)->CreateTypeA(arenaBuffer, 0x2000);

    arenaBuffer = backingAllocator->Allocate(0x800);
    if (arenaBuffer == 0) func_020c9be0();
    ((SafeAllocator*)((char*)allocatorState + 0x14))->CreateTypeA(arenaBuffer, 0x800);

    arenaBuffer = backingAllocator->Allocate(kRegionValue4000_3000);
    if (arenaBuffer == 0) func_020c9be0();
    ((SafeAllocator*)((char*)allocatorState + 0x28))->CreateTypeA(arenaBuffer, kRegionValue4000_3000);

    arenaBuffer = backingAllocator->Allocate(0x400);
    if (arenaBuffer == 0) func_020c9be0();
    ((SafeAllocator*)((char*)allocatorState + 0x3c))->CreateTypeA(arenaBuffer, 0x400);

    arenaBuffer = backingAllocator->Allocate(0x2000);
    if (arenaBuffer == 0) func_020c9be0();
    ((SafeAllocator*)((char*)allocatorState + 0x50))->CreateTypeA(arenaBuffer, 0x2000);

    int fieldSourceAddress = GetGlobalField0x1c020421a0();
    *(int*)((char*)allocatorState + kRegionValue7C_94) = *(int*)(fieldSourceAddress + kRegionValue5C_28);
}
