#include <globaldefs.h>

struct GameState;
ARM int CopyOutBattleField0x64f4(void* dst);

// USA: func_02011804
ARM unsigned char ReadBattleField0x64f4Byte(GameState* gameState) {
    unsigned char buf;
    CopyOutBattleField0x64f4(&buf);
    return buf;
}
