#include <globaldefs.h>

extern "C" int func_020d40bc(int, int, int);
int GetBattleReadyCode(void);
void SetBattleContextArrayEntry(int index, int value);

#if defined(jpn)
#define IssueBattleCommandSlot25 func_020d84e0
extern "C" ARM int func_020d84e0(int arg, int mode);
#endif

// USA: func_020d6a84
ARM int IssueBattleCommandSlot25(int arg, int mode) {
    int r = GetBattleReadyCode();
    if (r != 0) return r;
    if (mode != 0 && mode != 1) return 6;
    SetBattleContextArrayEntry(0x19, arg);
    r = func_020d40bc(0x19, 1, mode);
    if (r == 0) r = 2;
    return r;
}
