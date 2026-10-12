#include <globaldefs.h>

#if defined(jpn)
#define SetFieldFromBlocka4_021eaddc func_ov023_021ead40
#endif

int LoadBattleBlock020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021eaddc
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldFromBlocka4_021eaddc(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    unsigned int v = *(unsigned int*)(buf + 0xa4);
    func_ov017_021d6134(obj, v >> 0x16);
    return 1;
}
