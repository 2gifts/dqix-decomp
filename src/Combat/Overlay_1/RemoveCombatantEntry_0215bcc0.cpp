#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
int AbsPlus159IfNegative0215ad2c(int x);
struct Container02037364;
extern int data_ov001_02165769;

// USA: func_ov001_0215bcc0  (semantic: RemoveCombatantEntry_0215bcc0)
extern "C" ARM int func_ov001_0215bcc0(void* self, int mode) {
    GameState* battle = GameState::GetInstance();
    (int)BackgroundLoader::GetInstance();
    int mode2;
    int id = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4(self));
    mode2 = 3;
    if (mode >= 2) {
        mode2 = func_ov017_021d60f4((char*)self + 0x8);
    }
    GameObject* combatant = battle->GetGameObjectByIndex(id);
    if (combatant == NULL) return 0;
    unsigned char byteField = *((unsigned char*)combatant + 0x19);
    void* ptrField = *(void**)((char*)combatant + 0x14);
    ((Object3D*)((struct Container02037364*)combatant))->RemoveAnimationPackageByID(mode2);
    if (((Object3D*)combatant)->MaybeSetRegularAnimation((char const*)((int)ptrField), byteField) == 0) {
        ((Object3D*)combatant)->MaybeSetRegularAnimation((char const*)((int)&data_ov001_02165769), 0);
    }
    return 1;
}
