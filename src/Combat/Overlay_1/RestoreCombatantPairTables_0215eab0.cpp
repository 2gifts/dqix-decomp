#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
int GetWord0x0(int* obj);

struct Block0207df50 { unsigned int v[10]; };
struct Pair0207df50 { unsigned int v[2]; };
struct Foo0207df50 {
    struct Block0207df50 a;
    struct Block0207df50 b;
    unsigned int c;
    unsigned int d;
    struct Pair0207df50 p1;
    struct Pair0207df50 p2;
};
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);

// USA: func_ov001_0215eab0
ARM int RestoreCombatantPairTables_0215eab0(void* self, int mode) {
#if defined(jpn)
 enum { tableOffset = 0x27c };
#else
 enum { tableOffset = 0x2cc };
#endif
    GameState* bs = GameState::GetInstance();
    if (bs == NULL) {
        return 0;
    }
    int base = GetWord0x0((int*)bs);
    if (base == 0) {
        return 0;
    }
    int val = func_ov017_021d60f4(self);
    int addr;
    if (val < 0) {
        addr = base + tableOffset;
        addr = addr + 0xbd0;
    } else {
        addr = base + tableOffset + val * 0x70;
    }
    if (addr == 0) {
        return 0;
    }
    int flag = 1;
    if (mode >= 2) {
        flag = func_ov017_021d60f4((char*)self + 0x8);
    }
    if (flag != 0) {
        CopyInternalFields0207df50((struct Foo0207df50*)addr);
    }
    RestorePairTables0207df90((char*)addr);
    return 1;
}
