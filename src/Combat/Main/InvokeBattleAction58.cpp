#include <globaldefs.h>
#if defined(jpn)
extern "C" int func_020d68b4(int, int);
#define InvokeBattleActionSlot3_020d4e58 func_020d68b4
#else
int InvokeBattleActionSlot3_020d4e58(int, int);
#endif

// USA: func_020d4e48
ARM int InvokeBattleAction58_020d4e48(int a) {
    return InvokeBattleActionSlot3_020d4e58((int)(a), (int)(0));
}
