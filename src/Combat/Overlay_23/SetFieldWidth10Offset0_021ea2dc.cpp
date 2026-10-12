#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021ea2dc func_ov023_021ea240
#endif

struct S_ea2dc {
    char pad[0x84];
    unsigned int val : 10;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ea2dc  (semantic: SetFieldWidth10Offset0_021ea2dc)
extern "C" ARM int func_ov023_021ea2dc(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_ea2dc*)buf)->val);
    return 1;
}
