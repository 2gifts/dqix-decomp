#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "System/Memory.h"

#if defined(jpn)
enum { kLargeBufferOffset = 0x6d8c, kSmallBufferOffset = 0x5a70 };
#else
enum { kLargeBufferOffset = 0x6fcc, kSmallBufferOffset = 0x5cd0 };
#endif

struct SavedBufferState {
    unsigned char largeBuffer[0x200];
    unsigned int flags;
    unsigned char bits[10];
};

struct GameBufferState {
    unsigned char unknown0[kSmallBufferOffset];
    unsigned char bits[10];
    unsigned char unknownAfterSmall[kLargeBufferOffset - kSmallBufferOffset - 10];
    unsigned char largeBuffer[0x200];
    unsigned int flags;
};

// USA: func_020a9e30  (semantic: SyncBattleAndGrottoBuffers020a9e30)
extern "C" ARM int func_020a9e30(void* param) {
    SavedBufferState* saved = static_cast<SavedBufferState*>(param);
    GameState* battle = GameState::GetInstance();
    GameBufferState* buffers = reinterpret_cast<GameBufferState*>(battle);
    VectorizedInvertedMemcpy(saved->largeBuffer, buffers->largeBuffer, sizeof(saved->largeBuffer));
    VectorizedInvertedMemcpy(saved->bits, buffers->bits, sizeof(saved->bits));
    buffers->flags = saved->flags;
    struct GrottoStruct* grotto = battle->GetGrottoStruct();
    grotto->unknown_0[3] = (saved->flags & 1) != 0;
    buffers->flags = 0;
    return 1;
}
