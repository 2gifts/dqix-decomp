#include <globaldefs.h>

void* GetActiveCombatWork_ov000_02160130(void);
void ClearFlagIfParityMismatch02163710_02163710(void* obj, int flag);
void UpdateFlag8AndBit4_021636ac(void* objRaw);

// USA: func_ov025_021e82e4
ARM int UpdateFlagsBasedOnField8_021e82e4(unsigned char* param) {
    void* obj = GetActiveCombatWork_ov000_02160130();
    if (param[8]) {
        ClearFlagIfParityMismatch02163710_02163710(obj, 1);
    } else {
        UpdateFlag8AndBit4_021636ac(obj);
    }
    return 1;
}
