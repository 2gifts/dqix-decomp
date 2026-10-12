#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e9d94 func_ov023_021e9cf8
#endif

struct S_9d94 {
    char pad[0x3c];
    unsigned int val : 24;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9d94  (semantic: SetFieldWidth24Offset0_021e9d94)
extern "C" ARM int func_ov023_021e9d94(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_9d94*)buf)->val);
    return 1;
}
