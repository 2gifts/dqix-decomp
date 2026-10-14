#include <globaldefs.h>

#if defined(jpn)
enum { kBitsOffset = 0x21c };
#else
enum { kBitsOffset = 0x2a0 };
#endif

#include "GameState/GameState.h"

struct S02163c80 { char pad[kBitsOffset]; unsigned char* bitsPtr; };

struct Obj02086b98;
struct S_10088;
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned int index);
int AreListedCombatantsBit0Set(struct Obj02086b98* o);
int IsFlag10088Set_02010088(struct S_10088* obj);

// USA: func_ov000_02163c80
extern "C" ARM int func_ov000_02163c80(struct S02163c80* self, int checkEnemies) {
    GameState* bs = GameState::GetInstance();
    struct Obj02086b98* list = (struct Obj02086b98*)GetPtrField0x2a04_02010828(bs);
    int partyOk = 1;
    int i;
    int j;
    for (i = 0; i < 4; i++) {
        GameObject* m = bs->GetPartyMemberByIndex(i);
        if (m == NULL) continue;
        if (TestBitAt0x34_020a35e0(self->bitsPtr, i & 0xff)) continue;
        if (!(**(int**)((char*)m + 0x130) & 1)) partyOk = 0;
    }
    int enemiesOk = AreListedCombatantsBit0Set(list) != 0;
    if (checkEnemies) {
        enemiesOk = 1;
        for (j = 0; j < 4; j++) {
            GameObject* c = bs->GetCombatantByIndex(j);
            if (c == NULL) continue;
            if (!TestBitAt0x34_020a35e0(self->bitsPtr, j & 0xff)) continue;
            if (!IsFlag10088Set_02010088((struct S_10088*)c)) enemiesOk = 0;
        }
    }
    if (enemiesOk && !partyOk) {
        unsigned char* bits = self->bitsPtr;
        if (bits[0x24] != 0 || bits[0x25] != 0) return 1;
    }
    return 0;
}
