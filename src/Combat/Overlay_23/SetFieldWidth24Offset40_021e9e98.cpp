#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e9e98 func_ov023_021e9dfc
#endif

struct S_9e98 {
    char pad[0x40];
    unsigned int val : 24;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9e98  (semantic: SetFieldWidth24Offset40_021e9e98)
extern "C" ARM int func_ov023_021e9e98(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_9e98*)buf)->val);
    return 1;
}
