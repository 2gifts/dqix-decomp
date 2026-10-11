#include <globaldefs.h>
#include "GameState/GameState.h"

int TestBitAt0x34(unsigned char* obj, unsigned int index);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
extern "C" void* func_0202ae18(void);
void* GetPtrField0x2a04(GameState* battleStruct);
extern "C" int func_ov023_021f44d0(void* obj);

// JPN: func_ov023_021f4728
// USA: func_ov023_021f5150
extern "C" ARM int func_ov023_021f5150(void* p0, unsigned char* p1, int* p2, int* p3) {
#if defined(jpn)
 enum {regionalOffset=0x8b8};
#else
 enum {regionalOffset=0x950};
#endif
    GameState* bs = GameState::GetInstance();
    char* g = (char*)GetPtrField0x2a04(bs);
    func_0202ae18();

    int sum = 0;
    int i;
    for (i = 0; i < 4; i++) {
        if (!TestBitAt0x34(p1, (unsigned char)i)) continue;
        sum += p2[i];
        GameObject* c = GetCombatantWithFlag0x100(bs, i);
        if (c == 0) continue;
        int fVal = GetFieldAt0x150((unsigned char*)c);
        if (fVal == 0) continue;
        int* f = (int*)fVal;
        int idx = *(int*)((char*)f + regionalOffset);
        int* arr = (int*)((char*)f + 0x138);
        arr[idx] += p2[i];
    }

    int ratio = func_ov023_021f44d0(p0);
    *p3 = ratio;

    unsigned int cap = 0x98967f;
    if (cap - *(unsigned int*)(g + 0xf6c) < (unsigned int)ratio) {
        *(unsigned int*)(g + 0xf6c) = cap;
    } else {
        *(unsigned int*)(g + 0xf6c) += ratio;
    }

    return (sum == 0 && *p3 == 0) ? 1 : 0;
}
