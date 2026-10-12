#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e9b48 func_ov023_021e9aac
#endif

struct S_9b48 {
    char pad[0x18];
    unsigned int val : 9;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9b48  (semantic: SetFieldWidth9Offset0_021e9b48)
extern "C" ARM int func_ov023_021e9b48(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_9b48*)buf)->val);
    return 1;
}
