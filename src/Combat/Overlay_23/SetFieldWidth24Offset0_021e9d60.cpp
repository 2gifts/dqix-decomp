#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e9d60 func_ov023_021e9cc4
#endif

struct S_9d60 {
    char pad[0x38];
    unsigned int val : 24;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9d60  (semantic: SetFieldWidth24Offset0_021e9d60)
extern "C" ARM int func_ov023_021e9d60(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_9d60*)buf)->val);
    return 1;
}
