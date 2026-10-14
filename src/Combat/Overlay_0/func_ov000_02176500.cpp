#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct Container020e0310;

int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendPaletteTag_02041e70(char* dst, int palette);
int AppendXTag_02041a28(char* dst, int x);
int GetFieldByKey020e0434(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);

struct CombatStats_02176500 {
    char pad0[0x3b];
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
};

struct Combatant_02176500 {
    char pad0[0x138];
    struct CombatStats_02176500* stats;
};

struct Menu_02176500 {
    char pad0[4];
    struct Container020e0310* messages;
    char pad8[0x1c - 0x8];
    signed char cursor;
    char pad1d[0x4c - 0x1d];
    int combatantId;
};

extern int data_ov000_021834f8[6];

// USA: func_ov000_02176500
extern "C" ARM void func_ov000_02176500(struct Menu_02176500* menu, char* dst, int framed) {
    if (dst == NULL || menu->messages == NULL) {
        return;
    }
    GameObject* c = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), menu->combatantId);
    if (c == NULL) {
        return;
    }
    int flag = 0;
    if (((struct Combatant_02176500*)c)->stats->flag3) {
        flag = 1;
    }
    int cursor = menu->cursor;
    if (framed) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);
    for (int i = 0; i < 6; i++) {
        int item = data_ov000_021834f8[i];
        if (flag == 0 && item == 5) {
            AppendPaletteTag_02041e70(dst, 3);
        }
        AppendNameTag_02041b70(dst, item, (const char*)GetFieldByKey020e0434(menu->messages, (short)(item + 0x7534)));
        if (i == 5) {
            return;
        }
        if (i & 1) {
            AppendString02042058(dst, (const char*)GetFieldByKey020e0434(menu->messages, 0));
        } else {
            AppendXTag_02041a28(dst, 0x45);
        }
        AppendPaletteTag_02041e70(dst, 0xf);
    }
}
