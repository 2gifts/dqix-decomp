#include <globaldefs.h>
#if defined(jpn)
extern "C" int func_020d68b4(int, int);
#define InvokeBattleActionSlot3 func_020d68b4
#else
int InvokeBattleActionSlot3(int, int);
#endif


// USA: func_020d4e48
ARM int InvokeBattleAction58(int a) {
    return InvokeBattleActionSlot3((int)(a), (int)(0));
}
