#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_02161d8c
ARM int SetFieldFromGlobalCheck_02161d8c(void* obj) {
    int v = CheckField0NonZero_0202b7d8((int*)func_0202ae18());
    func_ov017_021d6134(obj, v);
    return 1;
}
