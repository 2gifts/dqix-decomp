#include <globaldefs.h>

void ResetBattleState0203c304(char* obj);

#if defined(jpn)
#define ResetBattleObject0203c4c4 func_0203c628
extern "C" ARM void func_0203c628(char* obj);
#endif

// USA: func_0203c4c4
ARM void ResetBattleObject0203c4c4(char* obj) {
    ResetBattleState0203c304(obj);
}
