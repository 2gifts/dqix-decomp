#include <globaldefs.h>
#if defined(jpn)
#define BUFFER_OFFSET 0x1dc
#define OWNED_OFFSET 0x1e0
#else
#define BUFFER_OFFSET 0x48c
#define OWNED_OFFSET 0x490
#endif
#include "Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

extern "C" void func_020a0c0c(void);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern AllocatorUnion data_02114e20;

// USA: func_020a395c  (semantic: ReleaseBattleBuffersAlt020a395c)
extern "C" ARM void func_020a395c(void) {
    GameState* battleStruct = GameState::GetInstance();
    int base = ((int)func_ov017_0218b5b0());
    unsigned char* word = battleStruct->GetTreasureMapLanguageData();
    TailForward02012da4(&data_02114e20, *(void**)(base + 0x4000 + BUFFER_OFFSET));
    TailForward02012da4(&data_02114e20, word);
    if (*(unsigned char*)(base + 0x4000 + OWNED_OFFSET) != 0) {
        func_020a0c0c();
        *(unsigned char*)(base + 0x4000 + OWNED_OFFSET) = 0;
    }
    battleStruct->SetTreasureMapLanguageDataPtr(0);
    *(void**)(base + 0x4000 + BUFFER_OFFSET) = 0;
}

// JPN: 0x020a5698
