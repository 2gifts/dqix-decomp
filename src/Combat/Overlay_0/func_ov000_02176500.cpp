#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct Container020e0310;

extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char* dst, int cursor);
int AppendNameTag(char* dst, int n, const char* name);
int AppendPaletteTag(char* dst, int palette);
int AppendXTag(char* dst, int x);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" int _Z20AppendString02042058PcPKc(char* dst, const char* src);

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
    GameObject* c = GetCombatantWithFlag0x100(GameState::GetInstance(), menu->combatantId);
    if (c == NULL) {
        return;
    }
    int flag = 0;
    if (((struct Combatant_02176500*)c)->stats->flag3) {
        flag = 1;
    }
    int cursor = menu->cursor;
    if (framed) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);
    for (int i = 0; i < 6; i++) {
        int item = data_ov000_021834f8[i];
        if (flag == 0 && item == 5) {
            AppendPaletteTag(dst, 3);
        }
        AppendNameTag(dst, item, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(menu->messages, (short)(item + 0x7534)));
        if (i == 5) {
            return;
        }
        if (i & 1) {
            _Z20AppendString02042058PcPKc(dst, (const char*)_Z21GetFieldByKey020e0434P17Container020e0310i(menu->messages, 0));
        } else {
            AppendXTag(dst, 0x45);
        }
        AppendPaletteTag(dst, 0xf);
    }
}
