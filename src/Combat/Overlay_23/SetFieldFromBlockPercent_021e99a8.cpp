#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e99a8 func_ov023_021e990c
#endif

int LoadBattleBlock020ac4c0(void* dst);
struct S_a0870;
int GetFieldPercentOver307(struct S_a0870* p);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e99a8  (semantic: SetFieldFromBlockPercent_021e99a8)
extern "C" ARM int func_ov023_021e99a8(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    int pct = GetFieldPercentOver307((struct S_a0870*)buf);
    func_ov017_021d6134(obj, pct);
    return 1;
}
