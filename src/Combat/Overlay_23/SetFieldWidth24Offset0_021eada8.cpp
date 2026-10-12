#include <globaldefs.h>

#if defined(jpn)
#define SetFieldWidth24Offset0_021eada8 func_ov023_021ead0c
#endif

struct S_eada8 {
    char pad[0xa8];
    unsigned int val : 24;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021eada8
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldWidth24Offset0_021eada8(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_eada8*)buf)->val);
    return 1;
}
