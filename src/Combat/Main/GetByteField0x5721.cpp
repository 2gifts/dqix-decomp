#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_02011538
ARM int GetByteField0x5721_02011538(GameState* battleStruct) {
    return *(unsigned char*)((char*)battleStruct + 0x5721);
}
