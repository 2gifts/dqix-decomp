#include <globaldefs.h>

extern "C" int func_020d40bc(int, int, int);
int GetBattleReadyCode_020d4204(void);
void SetBattleContextArrayEntry_020d404c(int index, int value);

// USA: func_020d6a84
ARM int IssueBattleCommandSlot25_020d6a84(int arg, int mode) {
    int r = GetBattleReadyCode_020d4204();
    if (r != 0) return r;
    if (mode != 0 && mode != 1) return 6;
    SetBattleContextArrayEntry_020d404c(0x19, arg);
    r = func_020d40bc(0x19, 1, mode);
    if (r == 0) r = 2;
    return r;
}
