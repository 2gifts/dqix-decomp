#include <globaldefs.h>
#include "GameState/GameState.h"

int IsField8Bit19Set_020ddb20(unsigned int* obj);
void* GetPtrField0x2a04_02010828(GameState* battleStruct);

struct KeyMap020a0a08;
int DecrementKeyValue020a0a08(struct KeyMap020a0a08* map, int key, int amount);

int LoadBattleBlock020ac4c0(void* dst);

struct S_a0504;
void AddClamped7BitField_020a0504(struct S_a0504* p, unsigned int amount);

int CopyInBattleField0x7540_020ac494(void* src);

// USA: func_020dddcc
ARM int TryDecrementAndAdjustField_020dddcc(void* obj) {
    char local[0xb0];
    if (!IsField8Bit19Set_020ddb20((unsigned int*)obj)) {
        return 0;
    }
    GameState* battle = GameState::GetInstance();
    void* ptr = GetPtrField0x2a04_02010828(battle);
    short key = *(short*)((char*)obj + 0x18);
    if (!DecrementKeyValue020a0a08((struct KeyMap020a0a08*)ptr, key, 1)) {
        return 0;
    }
    int field8 = *(int*)((char*)obj + 0x8);
    if ((unsigned int)field8 >> 31) {
        LoadBattleBlock020ac4c0(local);
        AddClamped7BitField_020a0504((struct S_a0504*)local, 1);
        CopyInBattleField0x7540_020ac494(local);
    }
    return 1;
}
