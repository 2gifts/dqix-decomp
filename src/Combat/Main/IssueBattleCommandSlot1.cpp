#include <globaldefs.h>

extern "C" int func_020d40bc(int, int);
int GetBattleReadyCode_020d4204(void);
void SetBattleContextArrayEntry_020d404c(int index, int value);

// USA: func_020d5004
ARM int IssueBattleCommandSlot1_020d5004(int arg) {
    int r = GetBattleReadyCode_020d4204();
    if (r != 0) return r;
    SetBattleContextArrayEntry_020d404c(1, arg);
    r = func_020d40bc(1, 0);
    if (r == 0) r = 2;
    return r;
}
