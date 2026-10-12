#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "System/Memory.h"

#if defined(jpn)
#define func_020a9e30 func_020aba80
enum { kLargeBufferOffset = 0x6d8c, kSmallBufferOffset = 0x5a70, kFlagBase = 0x6000, kFlagOffset = 0xf8c };
#else
enum { kLargeBufferOffset = 0x6fcc, kSmallBufferOffset = 0x5cd0, kFlagBase = 0x7000, kFlagOffset = 0x1cc };
#endif

// USA: func_020a9e30  (semantic: SyncBattleAndGrottoBuffers020a9e30)
extern "C" ARM int func_020a9e30(void* param) {
    void* obj = param;
    GameState* battle = GameState::GetInstance();
    VectorizedInvertedMemcpy(obj, (char*)battle + kLargeBufferOffset, 0x200);
    VectorizedInvertedMemcpy((char*)obj + 0x204, (char*)battle + kSmallBufferOffset, 0xa);
    int v = *(int*)((char*)obj + 0x200);
    *(int*)((char*)battle + kFlagBase + kFlagOffset) = v;
    struct GrottoStruct* grotto = battle->GetGrottoStruct();
    grotto->unknown_0[3] = (*(int*)((char*)obj + 0x200) & 0x1) != 0;
    char* p2 = (char*)battle + kFlagBase;
    *(int*)(p2 + kFlagOffset) = 0;
    return 1;
}
