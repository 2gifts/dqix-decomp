#include <globaldefs.h>
#include "GameState/GameState.h"

struct ListNode020378dc;
void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);

struct Param2_021e7470 { char pad[0x10]; unsigned char* node; };

// USA: func_ov025_021e7470
extern "C" ARM int func_ov025_021e7470(void* unused, struct Param2_021e7470* p2) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetGameObjectByIndex(0xc8);
    if (c) {
        ((Object3D*)((struct ListNode020378dc*)c))->Detach();
        ClearCombatantSlot_0200fd48(bs, 0xc8);
    }
    unsigned short idx = *(unsigned short*)(p2->node + 0x20);
    GameObject* c2 = bs->GetGameObjectByIndex(idx * 0xc + 0x1c);
    if (c2) {
        ((Object3D*)((unsigned char*)c2))->MakeVisible();
    }
    return 1;
}
