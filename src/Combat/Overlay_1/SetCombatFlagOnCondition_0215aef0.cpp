#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
extern "C" int func_ov017_0218b5b0(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int mask);
void SetCombatModeFromCase020dc2d0(int mode);
void* GetDataPtr02114e04_020d6c00(void);

// USA: func_ov001_0215aef0
ARM int SetCombatFlagOnCondition_0215aef0(void* obj) {
    int cond = func_ov017_021d60f4(obj);
    void* p = GetDataPtr02114e04_020d6c00();
    func_ov017_0218b5b0();
    if (cond != 0) {
        ClearFlags020466f4((struct FlagWord020466f4*)p, 1);
        SetCombatModeFromCase020dc2d0(0);
    } else {
        OrBitsIntoField0_020466e4((unsigned int*)p, 1);
    }
    return 1;
}
