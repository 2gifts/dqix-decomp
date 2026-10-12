#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e9d2c func_ov023_021e9c90
#endif

struct S_9d2c {
    char pad[0x34];
    unsigned int val : 24;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9d2c  (semantic: SetFieldWidth24Offset0_021e9d2c)
extern "C" ARM int func_ov023_021e9d2c(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_9d2c*)buf)->val);
    return 1;
}
