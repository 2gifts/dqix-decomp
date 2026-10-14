#include <globaldefs.h>

int GetBattleSubField0xbcForState_020d4ac8(void);
void ClearNodeMaskById_021f6600(void* obj, int id, int mask);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);

// USA: func_ov004_0215781c
ARM void ClearOrMaskNodesByState_0215781c(void* obj) {
    int state = GetBattleSubField0xbcForState_020d4ac8();
    for (int i = 0; i < 4; i++) {
        if (i == state) {
            ClearNodeMaskById_021f6600(obj, i + 0x29, 8);
        } else {
            func_ov023_021f65d4(obj, i + 0x29, 8);
        }
    }
}
