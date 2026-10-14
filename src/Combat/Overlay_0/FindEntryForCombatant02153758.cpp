#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantChecked_0200ff94(GameState*, int);
struct BinarySearchByComparatorStruct;
void* SearchWithComparator0206f4f0(struct BinarySearchByComparatorStruct* base, int key);

// USA: func_ov000_02153758
ARM void* FindEntryForCombatant02153758(void* obj, int idx) {
    int flag = (idx >= 0 && idx <= 3);
    if (flag) return 0;
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = GetCombatantChecked_0200ff94(battleStruct, idx);
    if (combatant == 0) return 0;
    int base = *(int*)((char*)obj + 0x8000 + 0xe18);
    short key = *(short*)((char*)combatant + 0x2);
    return SearchWithComparator0206f4f0((struct BinarySearchByComparatorStruct*)((char*)base + 0x678), key);
}
