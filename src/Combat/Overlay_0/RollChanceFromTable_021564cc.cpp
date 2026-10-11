#include <globaldefs.h>
#if defined(jpn)
enum { extraOffset = 0x144, indexOffset = 0x8b8 };
#else
enum { extraOffset = 0x150, indexOffset = 0x950 };
#endif
#include "GameState/GameState.h"
#include "Util/Random.h"

GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
int TestBitInArray0x8ec(unsigned char* obj, int index);
extern unsigned char data_ov000_02182ac5[];

struct Field150_021564cc {
    char pad[indexOffset];
    int idx;
};

// USA: func_ov000_021564cc
ARM int RollChanceFromTable_021564cc(struct Random* rand, int id) {
    GameState* bs = GameState::GetInstance();
    int inRange = (id >= 0 && id <= 3);
    if (!inRange) return 0;
    GameObject* combatant = GetCombatantWithFlag0x100(bs, id);
    if (combatant == NULL) return 0;
    unsigned char* field150 = *(unsigned char**)((char*)combatant + extraOffset);
    if (!TestBitInArray0x8ec(field150, 0xd0)) return 0;
    struct Field150_021564cc* field150b = *(struct Field150_021564cc**)((char*)combatant + extraOffset);
    int idx = field150b->idx;
    int tableVal = data_ov000_02182ac5[idx];
    int pick = NextRandomMax(rand, tableVal);
    return (pick == 1);
}
