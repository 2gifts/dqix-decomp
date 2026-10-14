#include <globaldefs.h>

extern "C" int func_020d40bc(int, int, int, int, int, int);
int GetBattleReadyCode_020d4204(void);
void SetBattleContextArrayEntry_020d404c(int index, int value);

#pragma optimize_for_size off
// USA: func_020d6ad4
ARM int IssueBattleCommandSlot29_020d6ad4(int arg, int a, int b, int c, unsigned short d) {
    int r = GetBattleReadyCode_020d4204();
    if (r != 0) return r;
    SetBattleContextArrayEntry_020d404c(0x1d, arg);
    r = func_020d40bc(0x1d, 4, a, b, c, d);
    if (r == 0) r = 2;
    return r;
}
