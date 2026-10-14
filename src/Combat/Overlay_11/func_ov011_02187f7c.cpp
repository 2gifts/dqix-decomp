#include <globaldefs.h>
#include "GameState/GameState.h"

int CheckBitsInField0x63dc_02011b50(void* obj, int mask);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
int GetFieldAt0x0_0202ba00(int* obj);
extern "C" int func_ov017_021d6134(void* arg0, int level);

// USA: func_ov011_02187f7c
extern "C" ARM int func_ov011_02187f7c(void* arg0) {
    int level = 0;
    GameState* battle = GameState::GetInstance();
    if (CheckBitsInField0x63dc_02011b50(battle, 1)) {
        if (CheckBitsInField0x63dc_02011b50(battle, 2)) level = 1;
        if (CheckBitsInField0x63dc_02011b50(battle, 4)) level = 2;
        if (CheckBitsInField0x63dc_02011b50(battle, 8)) level = 3;
        int* obj = (int*)func_0202ae18();
        if (CheckField0NonZero_0202b7d8(obj)) {
            if (GetFieldAt0x0_0202ba00(obj) == 6) level = 4;
        }
    }
    func_ov017_021d6134(arg0, level);
    return 1;
}
