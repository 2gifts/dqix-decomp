#include <globaldefs.h>

extern "C" int func_020d424c(int, int);
extern "C" int func_020d40bc(int, int, int);
void SetBattleContextArrayEntry_020d404c(int index, int value);
void* GetBattleContext_020d41d8(void);

// USA: func_020d51a8
ARM int IssueBattleCommandSlot8_020d51a8(int a0, int a1) {
    int r = func_020d424c(1, 2);
    if (r != 0) {
        return r;
    }
    char* ctx = (char*)GetBattleContext_020d41d8();
    *(unsigned short*)(ctx + 0x150) = 0;
    *(int*)(ctx + 0x14c) = 0;
    SetBattleContextArrayEntry_020d404c(8, a0);
    r = func_020d40bc(8, 1, a1);
    if (r == 0) {
        r = 2;
    }
    return r;
}
