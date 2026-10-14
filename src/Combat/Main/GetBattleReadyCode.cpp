#include <globaldefs.h>

int GetBattleStateCode_020d41e8(void);
void InvalidateDataCacheRange(const void* addr, unsigned int size);

extern char data_021142e0;

// USA: func_020d4204
ARM int GetBattleReadyCode_020d4204(void) {
    int state = GetBattleStateCode_020d41e8();
    if (state != 0) return state;
    InvalidateDataCacheRange((const void*)((int)*(unsigned short**)(*(char**)(&data_021142e0 + 4) + 4)), 2);
    return *(unsigned short*)*(unsigned short**)(*(char**)(&data_021142e0 + 4) + 4) <= 1 ? 3 : 0;
}
