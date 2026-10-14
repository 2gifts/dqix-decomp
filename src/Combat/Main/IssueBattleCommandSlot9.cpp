#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int);
void SetBattleContextArrayEntry_020d404c(int index, int value);

// USA: func_020d5214
ARM int IssueBattleCommandSlot9_020d5214(int arg) {
    int r = func_020d424c(1, 7);
    if (r != 0) return r;
    SetBattleContextArrayEntry_020d404c(9, arg);
    r = func_020d40bc(9, 0);
    if (r == 0) r = 2;
    return r;
}
