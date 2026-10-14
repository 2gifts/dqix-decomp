#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int);
void SetBattleContextArrayEntry_020d404c(int index, int value);

// USA: func_020d5490
ARM int IssueBattleCommandSlot11_020d5490(int arg) {
    int r = func_020d424c(1, 5);
    if (r != 0) return r;
    SetBattleContextArrayEntry_020d404c(0xb, arg);
    r = func_020d40bc(0xb, 0);
    if (r == 0) r = 2;
    return r;
}
