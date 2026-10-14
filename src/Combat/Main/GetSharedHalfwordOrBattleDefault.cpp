#include <globaldefs.h>

int GetBattleStateCode_020d41e8(void);

// USA: func_020d4aa8
ARM int GetSharedHalfwordOrBattleDefault_020d4aa8(void) {
    if (GetBattleStateCode_020d41e8()) return 0x8000;
    return *(unsigned short*)0x027ffcfa;
}
