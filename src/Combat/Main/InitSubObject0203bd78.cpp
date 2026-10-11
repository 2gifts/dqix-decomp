#include <globaldefs.h>

void ResetBattleState0203c304(char*);

// USA: func_0203bd78
// JPN: func_0203b7d0
ARM void InitSubObject0203bd78(char* obj) {
    ResetBattleState0203c304(obj + 0x10);
}
