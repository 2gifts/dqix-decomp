#include <globaldefs.h>

#if defined(jpn)
#define SetFieldWidth14Offset9_021ead40 func_ov023_021eaca4
#endif

struct S_ead40 {
    char pad[0xa0];
    unsigned int lo : 9;
    unsigned int val : 14;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ead40
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldWidth14Offset9_021ead40(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_ead40*)buf)->val);
    return 1;
}
