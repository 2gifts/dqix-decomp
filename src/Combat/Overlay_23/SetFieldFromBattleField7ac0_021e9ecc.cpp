#include <globaldefs.h>

int CopyOutBattleField0x7ac0_020ac0b4(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9ecc  (semantic: SetFieldFromBattleField7ac0_021e9ecc)
extern "C" ARM int func_ov023_021e9ecc(void* obj) {
    int v = 0;
    CopyOutBattleField0x7ac0_020ac0b4(&v);
    func_ov017_021d6134(obj, v);
    return 1;
}
