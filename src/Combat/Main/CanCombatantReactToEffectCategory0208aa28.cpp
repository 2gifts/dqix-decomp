#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantChecked(GameState* battleStruct, int combatantId);
int HasFlaggedSlotBit22Set020855d0(unsigned char* actor);
void* GetPtrField0x114(void* obj);
int CheckLow5BitsEqual1(unsigned short* obj);
int CheckLow5BitsEqual2(unsigned short* obj);
int CheckLow5BitsEqual3(unsigned short* obj);
int CheckLow5BitsEqual4(unsigned short* obj);
unsigned char GetByte0x26c(char* obj);


#if defined(jpn)
enum { ReactionActorOffset = 0x144 };
#else
enum { ReactionActorOffset = 0x150 };
#endif

// JPN: func_0208b31c
// USA: func_0208aa28
ARM int CanCombatantReactToEffectCategory0208aa28(unsigned char* obj, int combatantId, int flag) {
    ((unsigned int*)func_ov017_0218b5b0());
    GameState* battle = GameState::GetInstance();
    GameObject* c1 = GetCombatantChecked(battle, combatantId);
    GameObject* c2 = GetCombatantWithFlag0x100(battle, combatantId);
    if (c1 == NULL || (**(int**)((char*)c1 + 0x130) & 1)) {
        return 0;
    }
    if (HasFlaggedSlotBit22Set020855d0(*(unsigned char**)((char*)c2 + ReactionActorOffset)) != 0 || flag != 0) {
        return 0;
    }
    unsigned short* field = (unsigned short*)GetPtrField0x114(c1);
    switch (obj[4]) {
        case 0:
            if (!CheckLow5BitsEqual1(field)) return 0;
            break;
        case 1:
            if (!CheckLow5BitsEqual2(field)) return 0;
            break;
        case 2:
            if (!CheckLow5BitsEqual3(field)) return 0;
            break;
        case 3:
            if (!CheckLow5BitsEqual4(field)) return 0;
            break;
        default:
            break;
    }
    GameObject* c3 = battle->GetUnknownGameObject();
    if (*(short*)((char*)c3 + 0xb2) == 0) {
        return 0;
    }
    return GetByte0x26c((char*)c3) == 0 ? 1 : 0;
}
