#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define SetListField22FromCombatant_021a4e0c func_ov017_021a5880
#endif

struct PartySelectionState {
    unsigned char unknown00[0x22];
    short selectedPartyIndex;
};

extern "C" void func_ov017_021c12fc(char* resources, unsigned char, unsigned char);

// USA: func_ov017_021a4e0c
#if defined(jpn)
extern "C"
#endif
ARM void SetListField22FromCombatant_021a4e0c(char* resourceStorage) {
    GameObject* member = GameState::GetInstance()->GetUnknownGameObject();
    if (member == NULL) return;
    short index = member->obj3D_.unknown_4_;
    GameResources* resources = (GameResources*)resourceStorage;
    PartySelectionState* selection = (PartySelectionState*)resources->unknown_ptr_array_371c[0];
    selection->selectedPartyIndex = index;
    func_ov017_021c12fc(resourceStorage, 1, 1);
}
