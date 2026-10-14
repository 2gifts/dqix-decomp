#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
extern "C" int func_0202c508(void* obj);
extern "C" int func_ov017_02195760(int obj);
void SetByte2IfGlobalFlagSet_020e3778(unsigned char* p);
extern "C" void func_ov017_021ced48(int a, unsigned char b);
struct SearchStruct;
int TestFlagBitAt0xe_0202c578(struct SearchStruct* obj, int value);

// USA: func_020e35a0
ARM void UpdateGlobalAndCombatantFlagBytes_020e35a0(unsigned char* p) {
    GameState* battleStruct = GameState::GetInstance();
    int obj2 = ((int)func_ov017_0218b5b0());
    int* searchObj = func_0202ae18();
    if (!CheckField0NonZero_0202b7d8(searchObj)) return;

    if (func_0202c508(searchObj)) {
        int i;
        if (func_ov017_02195760(obj2)) {
            for (i = 0; i < 4; i++) {
                if (p[0] & (1 << i)) {
                    if (i == 0) {
                        SetByte2IfGlobalFlagSet_020e3778(p);
                    } else {
                        func_ov017_021ced48(1, (unsigned char)i);
                    }
                }
            }
            p[1] |= p[0];
            p[0] = 0;
        }
        for (i = 1; i < 4; i++) {
            if (!battleStruct->GetGameObjectByIndex(i) || TestFlagBitAt0xe_0202c578((struct SearchStruct*)searchObj, i)) {
                p[0] &= ~(1 << i);
                p[1] &= ~(1 << i);
            }
        }
    } else {
        if (TestFlagBitAt0xe_0202c578((struct SearchStruct*)searchObj, 0)) {
            p[2] = 1;
        }
    }
}
