#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021eac3c func_ov023_021eaba0
#endif

struct S_eac3c {
    char pad[0x9c];
    unsigned int val : 17;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eac3c  (semantic: SetFieldWidth17Offset0_021eac3c)
extern "C" ARM int func_ov023_021eac3c(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_eac3c*)buf)->val);
    return 1;
}
