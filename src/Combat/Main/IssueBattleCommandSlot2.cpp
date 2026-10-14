#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int);
void SetBattleContextArrayEntry_020d404c(int index, int value);

// USA: func_020d503c
ARM int IssueBattleCommandSlot2_020d503c(int arg) {
    int r = func_020d424c(1, 2);
    if (r != 0) return r;
    SetBattleContextArrayEntry_020d404c(2, arg);
    r = func_020d40bc(2, 0);
    if (r == 0) r = 2;
    return r;
}
