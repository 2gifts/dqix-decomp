#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e9dfc func_ov023_021e9d60
#endif

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov023_021e9dfc
extern "C" ARM int func_ov023_021e9dfc(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    unsigned int v = *(unsigned int*)(buf + 0x28);
    v = (v << 10) >> 22;
    func_ov017_021d6134(obj, v);
    return 1;
}
