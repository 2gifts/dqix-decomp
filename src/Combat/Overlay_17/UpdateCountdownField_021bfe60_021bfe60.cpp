#include <globaldefs.h>
#include "GameState/GameState.h"

void SetByteField0x253_020397c0(void* obj);
int GetFieldIfFlag4_020100f8(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);

// USA: func_ov017_021bfe60
ARM int UpdateCountdownField_021bfe60_021bfe60(unsigned char* self) {
    GameState* battle = GameState::GetInstance();
    int value = battle->GetEffectiveDeltaTime();
    unsigned short* field8 = (unsigned short*)(self + 8);
    if ((unsigned int)value < (unsigned int)*field8) {
        *field8 = *field8 - value;
        return 5;
    }

    *field8 = 0;
    GameObject* combatant = battle->GetUnknownGameObject();
    if (combatant != NULL) {
        SetByteField0x253_020397c0(combatant);
    }
    void* ov = func_ov017_0218b5b0();
    int flag = GetFieldIfFlag4_020100f8((char*)battle);
    if (flag != 0) {
        SetField0x23cTrue_020a27ac((void*)flag);
    }
    if (ov != NULL) {
        ClearBitsInField4_0203b4e8((unsigned int*)ov, 0x80);
    }
    *field8 = 0x12c;
    return 6;
}
