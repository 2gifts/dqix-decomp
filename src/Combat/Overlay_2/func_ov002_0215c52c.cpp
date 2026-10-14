#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;

struct GameState;
unsigned char ReadBattleField0x64f4Byte_02011804(GameState* gameState);
void AppendFrameTag02041c08(char *buf, int x, int a, int b, int c, int d);
void AppendCursorTag_02041ea4(char *buf, int x);
const char *GetFieldByKey020e0434(Container020e0310 *tbl, int key);
void AppendFormatted02041fac(char *buf, int str, int n);
void AppendNameTag_02041b70(char *buf, int i, const char *str);
void AppendString02042058(char *buf, const char *str);

// USA: func_ov002_0215c52c
extern "C" ARM void func_ov002_0215c52c(unsigned char *self, char *buf, int frame) {
    if (buf == 0) return;
    short key = 0x3ea;
    int n     = 3;
    short x   = *(short *) (self + 0x1be4);
    if (ReadBattleField0x64f4Byte_02011804(GameState::GetInstance()) == 0) n = 2;
    if (frame) AppendFrameTag02041c08(buf, x, 8, 5, 5, 5);
    AppendCursorTag_02041ea4(buf, x);
    AppendFormatted02041fac(
        buf, (int) GetFieldByKey020e0434((Container020e0310 *) (self + 0x20), 1000), 0x18);
    for (int i = 0; i < n; i++) {
        AppendNameTag_02041b70(buf, i, GetFieldByKey020e0434((Container020e0310 *) (self + 0x20), key++));
        if (i != n - 1) AppendString02042058(buf, *(const char **) (self + 0x1bdc));
    }
}
