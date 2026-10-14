#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_02010828
ARM void* GetPtrField0x2a04_02010828(GameState* battleStruct) {
#if defined(jpn)
    return (char*)battleStruct + 0x27a4;
#else
    return (char*)battleStruct + 0x2a04;
#endif
}
