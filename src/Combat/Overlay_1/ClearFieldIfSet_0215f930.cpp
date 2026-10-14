#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetFieldPtrAt0x5ca4_02010768(void* obj);
void SetField0x3b0Value_020100c4(GameState* battleStruct, int value);

// USA: func_ov001_0215f930
ARM int ClearFieldIfSet_0215f930(void) {
    GameState* battleStruct = GameState::GetInstance();
    int* p = (int*)GetFieldPtrAt0x5ca4_02010768(battleStruct);
    int val = p[1];
    if (val != 0) {
        SetField0x3b0Value_020100c4(battleStruct, val);
        p[1] = 0;
    }
    return 1;
}
