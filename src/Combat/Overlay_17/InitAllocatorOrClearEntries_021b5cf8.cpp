#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

extern "C" void* func_02012fe4(void);
extern "C" void func_ov017_0218d510(int a, void* b);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;
int GetField0x3acValue_020100a8(GameState* battleStruct);
struct Holder020159c0;
void ClearMatchingEntries020159c0(struct Holder020159c0* holder, int key);
extern char data_ov017_021d7bf8[];

// USA: func_ov017_021b5cf8  (semantic: InitAllocatorOrClearEntries_021b5cf8)
extern "C" ARM int func_ov017_021b5cf8(char* self) {
    if (*(unsigned short*)(self + 0x12) == 0x5617) {
        self[0x54] = 1;
        ((SafeAllocator*)(self + 0x58))->ResetAllocatorPointer();
        ((SafeAllocator*)(self + 0x58))->CreateTypeA(AllocateAligned4_02012d88(&data_02114e20, 0x4000), 0x4000);
        ((SafeAllocator*)(self + 0x58))->Reset();
        func_ov017_0218d510(((int)func_ov017_0218b5b0()), self + 0x58);
    } else {
        GameState* battle = GameState::GetInstance();
        void* holder = func_02012fe4();
        ClearMatchingEntries020159c0((struct Holder020159c0*)holder, (signed char)GetField0x3acValue_020100a8(battle));
        char buf[0x80];
        sprintf(buf, data_ov017_021d7bf8, *(signed char*)(self + 0x17), *(signed short*)(self + 0x14));
        *(int*)(self + 0x28) = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
    }
    return 3;
}
