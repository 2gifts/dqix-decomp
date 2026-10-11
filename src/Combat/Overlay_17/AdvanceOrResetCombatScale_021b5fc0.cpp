#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021b5a30(unsigned char* obj);
extern "C" void func_ov017_021b6090(unsigned char* obj);
extern "C" void func_02094ab0(int a);
int GetGlobal02109400(void);
int GetGlobalField0x1c020421a0(void);
int HasNonZeroByteAtOfField498_0218d75c_0218d75c(void* obj);
void SetByteField0x253(void* obj);

// JPN: func_ov017_021b6574
// USA: func_ov017_021b5fc0  (semantic: AdvanceOrResetCombatScale_021b5fc0)
extern "C" ARM int func_ov017_021b5fc0(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x228};
#else
 enum {regionalOffset0=0x2d8};
#endif
    GameState* battleStruct = GameState::GetInstance();
    int scale = battleStruct->GetTickCount();
    func_ov017_0218b5b0();

    if (obj[0x54] != 0) {
        void* p = func_ov017_0218b5b0();
        if (HasNonZeroByteAtOfField498_0218d75c_0218d75c(p) != 0) {
            return 5;
        }
        obj[0x16] = 0;
        func_02094ab0(GetGlobal02109400());
        func_ov017_021b5a30(obj);
        obj[0x1] = 1;
        char* g = (char*)GetGlobalField0x1c020421a0();
        *(int*)(g + regionalOffset0) = 0;
        return 6;
    }

    func_ov017_021b6090(obj);
    char* g = (char*)GetGlobalField0x1c020421a0();
    unsigned char f16 = obj[0x16];
    if (scale < f16) {
        obj[0x16] = f16 - scale;
        goto returnFive021b5fc0;
    }
    obj[0x16] = 0;
    func_02094ab0(GetGlobal02109400());
    SetByteField0x253(*(void**)(obj + 0x1c));
    func_ov017_021b5a30(obj);
    obj[0x1] = 1;
    *(int*)(g + regionalOffset0) = 0;
    return 6;
returnFive021b5fc0:
    return 5;
}
