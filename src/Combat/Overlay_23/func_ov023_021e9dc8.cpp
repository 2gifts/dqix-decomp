#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e9dc8 func_ov023_021e9d2c
#endif

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void* obj, int val);

struct Packed021e9dc8 { unsigned int val : 24; unsigned int hi : 8; };

// USA: func_ov023_021e9dc8
extern "C" ARM int func_ov023_021e9dc8(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    unsigned int v = ((Packed021e9dc8*)(buf + 8))->val;
    func_ov017_021d6134(obj, v);
    return 1;
}
