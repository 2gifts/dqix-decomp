#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct SearchStruct;
void SetSearchFlagBitAt0xc(struct SearchStruct* obj, int value);
extern "C" void* func_0202ae18(void);
extern "C" void func_ov017_0218f064(GameResources* ov, int id, int b, int c, int d);

// USA: func_ov017_021b0a7c  (semantic: ProcessSlotStatesAndNotify_021b0a7c)
extern "C" ARM void func_ov017_021b0a7c(unsigned char* obj) {
    unsigned char* base;
    GameState* bs;
    GameResources* ov;
    int i;
    bs = GameState::GetInstance();
    ov = func_ov017_0218b5b0();
    base = obj + 0x1b;
    for (i = 0; i < 4; i++) {
        if (base[i] != 0) {
            if (!bs->GetGameObjectByIndex(i)) {
                if (base[i] == 1) {
                    func_ov017_0218f064(ov, i, 0x200, 0, 0);
                } else {
                    func_ov017_0218f064(ov, i, 0x1000, 0, 0);
                }
            }
        }
    }
    struct SearchStruct* ss = (struct SearchStruct*)func_0202ae18();
    int j;
    for (j = 0; j < 4; j++) {
        if ((obj + j)[0x1b] == 1) {
            SetSearchFlagBitAt0xc(ss, j);
        }
    }
}
