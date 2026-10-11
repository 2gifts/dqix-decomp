#include <globaldefs.h>

void ResetBattleState0203c304(char*);

// USA: func_0203bd78
ARM void InitSubObject0203bd78(char* obj) {
    ResetBattleState0203c304(obj + 0x10);
}
