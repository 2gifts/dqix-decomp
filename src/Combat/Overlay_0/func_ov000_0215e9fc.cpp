#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct S_10088;
unsigned char CopyOutRegion0x571d(char* obj, void* dst);
int ClassifyField0x81fe(char* base);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);
int IsFlag10088Set(struct S_10088* obj);

struct SubObj_0215e9fc {
    unsigned char pad[0x56b];
    unsigned char nibble : 4;
};

struct Combatant_0215e9fc {
    unsigned char pad[0x150];
    struct SubObj_0215e9fc* sub;
};

// USA: func_ov000_0215e9fc
extern "C" ARM int func_ov000_0215e9fc(char* obj, short* out, int max, unsigned int flags) {
    GameState* gs = GameState::GetInstance();
    unsigned char ids[4];
    int n = CopyOutRegion0x571d((char*)gs, ids);
    int checkNibble;
    int checkFlag10088;
    int i;
    int id;
    GameObject* c;
    int count = 0;
    checkFlag10088 = flags & 1;
    i = 0;
    checkNibble = flags & 8;
    for (; i < n; i++) {
        id = ids[i];
        if (ClassifyField0x81fe(obj) != 0 && id != 0) continue;
        if (!TestBitAt0x34(*(unsigned char**)(obj + 0x8e18), (unsigned char)id)) continue;
        c = GetCombatantWithFlag0x100(gs, id);
        if (c == NULL) continue;
        if (IsFlag0x18Bit0x2000Set(c)) continue;
        if (checkFlag10088 && IsFlag10088Set((struct S_10088*)c)) continue;
        if (checkNibble) {
            int hasNibble;
            struct SubObj_0215e9fc* sub = ((struct Combatant_0215e9fc*)c)->sub;
            if (sub != NULL) {
                hasNibble = sub->nibble != 0;
            } else {
                hasNibble = 0;
            }
            if (hasNibble) continue;
        }
        out[count] = id;
        count++;
        if (count == max) return count;
    }
    return count;
}
