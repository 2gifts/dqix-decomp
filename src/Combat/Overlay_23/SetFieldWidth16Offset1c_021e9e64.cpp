#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e9e64 func_ov023_021e9dc8
#endif

struct S_9e64 {
    char pad[0x1c];
    unsigned int val : 16;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9e64  (semantic: SetFieldWidth16Offset1c_021e9e64)
extern "C" ARM int func_ov023_021e9e64(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_9e64*)buf)->val);
    return 1;
}
