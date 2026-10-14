#include <globaldefs.h>
#include "GameState/GameState.h"
void* GetPtrField0x2a04_02010828(GameState*);
#include "std_library_functions.h"

// USA: func_02039768
ARM void CopyToBattleField02039768(int unused, void* src) {
    GameState* battleStruct = GameState::GetInstance();
    memcpy((char*)GetPtrField0x2a04_02010828((GameState*)(battleStruct)) + 0x2c8d, src, 7);
}
