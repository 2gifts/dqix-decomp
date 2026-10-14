#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int);
void SetBattleContextArrayEntry_020d404c(int index, int value);

// USA: func_020d4f3c
ARM int IssueBattleCommandSlot6_020d4f3c(int arg) {
    int r = func_020d424c(1, 2);
    if (r != 0) return r;
    SetBattleContextArrayEntry_020d404c(6, arg);
    r = func_020d40bc(6, 0);
    if (r == 0) r = 2;
    return r;
}
