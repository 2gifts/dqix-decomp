#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021ea310 func_ov023_021ea274
#endif

struct S_ea310 {
    char pad[0x84];
    unsigned int lo : 10;
    unsigned int val : 16;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea310  (semantic: SetFieldWidth16Offset10_021ea310)
extern "C" ARM int func_ov023_021ea310(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_ea310*)buf)->val);
    return 1;
}
