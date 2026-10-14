#include <globaldefs.h>

int LoadBattleBlock020ac4c0(void* dst);
extern "C" int func_ov017_021d60f4(void*);
int CopyInBattleField0x7540_020ac494(void* src);

// USA: func_ov023_021e92f0
ARM int SetBattleBlockBit_021e92f0(void* obj) {
    unsigned char buf[0xb0];
    LoadBattleBlock020ac4c0(buf);
    int idx = func_ov017_021d60f4(obj);
    int q = idx / 32;
    int r = idx % 32;
    unsigned int* bits = (unsigned int*)(buf + 0x4c);
    bits[q] = bits[q] | (1 << r);
    CopyInBattleField0x7540_020ac494(buf);
    return 1;
}
