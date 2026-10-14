#include <globaldefs.h>

extern unsigned short data_021142e0;

// USA: func_020d41e8
ARM int GetBattleStateCode_020d41e8(void) {
    return data_021142e0 ? 0 : 3;
}
