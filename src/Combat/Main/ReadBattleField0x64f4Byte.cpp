#include <globaldefs.h>

struct GameState;
ARM int CopyOutBattleField0x64f4_020ac78c(void* dst);

// USA: func_02011804
ARM unsigned char ReadBattleField0x64f4Byte_02011804(GameState* gameState) {
    unsigned char buf;
    CopyOutBattleField0x64f4_020ac78c(&buf);
    return buf;
}
