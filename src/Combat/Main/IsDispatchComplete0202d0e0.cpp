#include <globaldefs.h>
int IssueBattleCommandSlot11_020d5490(int);

extern "C" int func_0202d108(void);
void SetField0x48UnlessState9Or10_0202c848(int arg);

// USA: func_0202d0e0
ARM int IsDispatchComplete0202d0e0(void) {
    int r = IssueBattleCommandSlot11_020d5490((int)(func_0202d108));
    if (r == 2) {
        return 1;
    }
    SetField0x48UnlessState9Or10_0202c848(r);
    return 0;
}
