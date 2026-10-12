#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e9e30 func_ov023_021e9d94
#endif

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void* obj, int val);

struct Packed021e9e30 { unsigned int val : 12; unsigned int hi : 20; };

// USA: func_ov023_021e9e30
extern "C" ARM int func_ov023_021e9e30(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    unsigned int v = ((Packed021e9e30*)(buf + 0x28))->val;
    func_ov017_021d6134(obj, v);
    return 1;
}
