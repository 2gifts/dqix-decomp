#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021eac70 func_ov023_021eabd4
#endif

struct S_eac70 {
    char pad[0x9c];
    unsigned int lo : 17;
    unsigned int val : 7;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eac70  (semantic: SetFieldWidth7Offset17_021eac70)
extern "C" ARM int func_ov023_021eac70(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_eac70*)buf)->val);
    return 1;
}
