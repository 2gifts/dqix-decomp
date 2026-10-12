#include <globaldefs.h>

#if defined(jpn)
#define SetFieldFromBlock28_021e9f00 func_ov023_021e9e64
#endif

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9f00
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldFromBlock28_021e9f00(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    unsigned int v = *(unsigned int*)(buf + 0x28);
    func_ov017_021d6134(obj, v >> 0x16);
    return 1;
}
