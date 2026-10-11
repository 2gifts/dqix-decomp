#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"


#if defined(jpn)
#define BATTLE_BUFFER_FIELD 0x1dc
#else
#define BATTLE_BUFFER_FIELD 0x48c
#endif

// USA: func_020a39d8
ARM void ReleaseBattleBuffers020a39d8(SafeAllocator* alloc) {
    GameState* battleStruct = GameState::GetInstance();
    int base = ((int)func_ov017_0218b5b0());
    int word = (int)battleStruct->GetTreasureMapLanguageData();
    alloc->Free(*(void**)(base + 0x4000 + BATTLE_BUFFER_FIELD));
    alloc->Free((void*)word);
    battleStruct->SetTreasureMapLanguageDataPtr(0);
    *(void**)(base + 0x4000 + BATTLE_BUFFER_FIELD) = NULL;
}

// JPN: 0x020a5714
