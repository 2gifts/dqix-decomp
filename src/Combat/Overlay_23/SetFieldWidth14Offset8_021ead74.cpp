#include <globaldefs.h>

#if defined(jpn)
#define SetFieldWidth14Offset8_021ead74 func_ov023_021eacd8
#endif

struct S_ead74 {
    char pad[0xa4];
    unsigned int lo : 8;
    unsigned int val : 14;
};

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021ead74
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldWidth14Offset8_021ead74(void* obj) {
    char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct S_ead74*)buf)->val);
    return 1;
}
