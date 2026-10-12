#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e9be4 func_ov023_021e9b48
#endif

int LoadBattleBlock020ac4c0(void* dst);

struct ShortPair021e9be4 { unsigned short lo, hi; };
extern "C" ShortPair021e9be4 func_ov023_021e8fe8(ShortPair021e9be4 v, int kind);
extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov023_021e9be4
extern "C" ARM int func_ov023_021e9be4(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);

    ShortPair021e9be4 result = func_ov023_021e8fe8(*(ShortPair021e9be4*)(buf + 0x0), 0);

    func_ov017_021d6134(obj, result.lo);
    func_ov017_021d6134((char*)obj + 8, *(unsigned char*)&result.hi);
    return 1;
}
