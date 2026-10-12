#include <globaldefs.h>

#if defined(jpn)
#define SetClampedFieldFromBlock48_021e9f9c func_ov023_021e9f00
#endif

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9f9c
#if defined(jpn)
extern "C"
#endif
ARM int SetClampedFieldFromBlock48_021e9f9c(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    unsigned int v = *(unsigned int*)(buf + 0x48);
    if (v > 0x7fffffff) v = 0x7fffffff;
    func_ov017_021d6134(obj, v);
    return 1;
}
