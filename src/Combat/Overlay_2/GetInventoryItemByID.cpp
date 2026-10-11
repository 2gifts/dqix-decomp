#include <globaldefs.h>
#if defined(jpn)
#define COMBATANT_ID_OFFSET 0x1ae8
#else
#define COMBATANT_ID_OFFSET 0x1c20
#endif
#include "GameState/GameState.h"

void* GetPtrField0x2a04(GameState* battleStruct);
int GetFieldAt0x150(unsigned char* obj);

inline char* AddOffset204(char* p) { return p + 0x204; }
inline char* AddOffsetC00(char* p) { return p + 0xc00; }

// USA: func_ov002_0215707c
// KEEP-NAME
extern "C" ARM int GetInventoryItemByID(void* self, int idx, int kind) {
    if (idx < 0) {
        return -1;
    }
    if (kind < 0) {
        return -1;
    }
    GameState* battle = GameState::GetInstance();
    if (kind == 5) {
        char* p = (char*)GetPtrField0x2a04(battle);
        char* table = AddOffsetC00(AddOffset204(p));
        return *(short*)(table + 0xc + idx * 2);
    }
    if (kind == 4) {
        char* p = (char*)GetPtrField0x2a04(battle);
        return *(short*)(p + 0xc + idx * 2);
    }
    signed char id = *(signed char*)((char*)self + COMBATANT_ID_OFFSET);
    GameObject* combatant = GetCombatantWithFlag0x100(battle, id);
    if (combatant == 0) {
        return -1;
    }
    return *(short*)((char*)GetFieldAt0x150((unsigned char*)combatant) + 0x454 + idx * 2);
}
