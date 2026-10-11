#include <globaldefs.h>
#if defined(jpn)
enum { kStateOffset = 0x5a68 };
#else
enum { kStateOffset = 0x5cc8 };
#endif

#include "Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern AllocatorUnion data_02114e20;

extern "C" int func_02075910(int a, void* p, unsigned int size, int c);
extern "C" int func_02075acc(int a, void* p, unsigned int size, int c);

// USA: func_020abca8
ARM int AllocateAndProcessScratchBuffer020abca8() {
    GameState* bs = GameState::GetInstance();
    int zero = 0;
    *(unsigned char*)((char*)bs + kStateOffset) = zero;

    void* alloc = AllocateAligned4(&data_02114e20, 0x6fe4);
    if (alloc != NULL) {
        zero = func_02075910(0x10, alloc, 0x6fe4, zero);
        if (zero != 0) {
            func_02075acc(0x8010, alloc, 0x6fe4, 0);
        }
        TailForward02012da4(&data_02114e20, alloc);
    }
    return zero;
}
