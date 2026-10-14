#include <globaldefs.h>
int IssueBattleCommandSlot0_020d4fa4(int, int, int, int);

// USA: func_020d4f8c
ARM int CallFunc020d4fa4Flag_020d4f8c(int a, int b, int c, int d) {
    int v = 1;
    if (d == 0) v |= 2;
    return IssueBattleCommandSlot0_020d4fa4((int)(a), (int)(b), (int)(c), (int)(v));
}
