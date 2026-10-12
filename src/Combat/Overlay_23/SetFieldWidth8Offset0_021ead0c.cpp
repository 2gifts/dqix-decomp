#include <globaldefs.h>

#if defined(jpn)
#define SetFieldWidth8Offset0_021ead0c func_ov023_021eac70
#endif

struct S_ead0c {
    char pad[0xa4];
    unsigned int val : 8;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ead0c
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldWidth8Offset0_021ead0c(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_ead0c*)buf)->val);
    return 1;
}
