#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

int LoadBattleBlock020ac460(void* dst);
int LoadBattleBlock020ac4c0(void* dst);
int SetBattleFlagBits020ac3c8(unsigned int* dst, short* indices, int count);
int CopyInBattleField0x7540_020ac494(void* src);

struct S_a03c4 {
    char pad[0x10];
    unsigned int val : 9;
    unsigned int hi : 23;
};
void AddClamped9BitFieldAt0x10_020a03c4(struct S_a03c4* p, unsigned int amount);

// USA: func_ov023_021ed724
extern "C" ARM int func_ov023_021ed724(void* obj, short* src, int count) {
    if (obj == 0) return 0;
    if (src == 0) return 0;
    if (count == 0) return 0;

    short shortsBuf[50];
    char block[0xb0];
    unsigned int dst[15];

    int flag = 0;
    LoadBattleBlock020ac460(dst);
    memset(shortsBuf, 0, 0x64);
    for (int i = 0; i < count; i++) {
        shortsBuf[i] = src[i];
    }
    SetBattleFlagBits020ac3c8(dst, shortsBuf, count);
    LoadBattleBlock020ac4c0(block);
    if (((struct S_a03c4*)block)->val == 0) {
        flag |= 1;
    }
    AddClamped9BitFieldAt0x10_020a03c4((struct S_a03c4*)block, count);
    CopyInBattleField0x7540_020ac494(block);
    return flag;
}
