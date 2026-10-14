#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct S_10088;
unsigned char CopyOutRegion0x571d_020114ec(char* obj, void* dst);
int ClassifyField0x81fe_ov000_0215fc60(char* base);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned int index);
int IsFlag0x18Bit0x2000Set_ov000_02153c0c(GameObject* combatant);
int IsFlag10088Set_02010088(struct S_10088* obj);

struct SubObj_0215e9fc {
    unsigned char pad[0x56b];
    unsigned char nibble : 4;
};

struct Combatant_0215e9fc {
#if defined(jpn)
    unsigned char pad[0x144];
#else
    unsigned char pad[0x150];
#endif
    struct SubObj_0215e9fc* sub;
};

// USA: func_ov000_0215e9fc
extern "C" ARM int func_ov000_0215e9fc(char* obj, short* out, int max, unsigned int flags) {
    GameState* gs = GameState::GetInstance();
    unsigned char ids[4];
    int n = CopyOutRegion0x571d_020114ec((char*)gs, ids);
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
        if (ClassifyField0x81fe_ov000_0215fc60(obj) != 0 && id != 0) continue;
        if (!TestBitAt0x34_020a35e0(*(unsigned char**)(obj + 0x8e18), (unsigned char)id)) continue;
        c = GetCombatantWithFlag0x100_0200ff1c(gs, id);
        if (c == NULL) continue;
        if (IsFlag0x18Bit0x2000Set_ov000_02153c0c(c)) continue;
        if (checkFlag10088 && IsFlag10088Set_02010088((struct S_10088*)c)) continue;
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
