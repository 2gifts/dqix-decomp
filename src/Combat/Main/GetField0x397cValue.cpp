#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_020100b0
ARM unsigned char GetField0x397cValue_020100b0(GameState* battleStruct) {
#if defined(jpn)
    return *(unsigned char*)((char*)battleStruct + 0x371c);
#else
    return *(unsigned char*)((char*)battleStruct + 0x397c);
#endif
}
