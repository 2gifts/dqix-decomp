#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021eac08 func_ov023_021eab6c
#endif

struct S_eac08 {
    char pad[0x98];
    unsigned int lo : 24;
    unsigned int val : 7;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eac08  (semantic: SetFieldWidth7Offset24_021eac08)
extern "C" ARM int func_ov023_021eac08(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_eac08*)buf)->val);
    return 1;
}
