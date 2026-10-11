#include <globaldefs.h>
#include "GameState/GameState.h"

void EnqueueEventTag33_021d2738(unsigned char a, unsigned char b);

// USA: func_ov017_021c12b0
ARM void EnqueueTag33ForListedCombatant_021c12b0(unsigned char param) {
	void* self = func_ov017_0218b5b0();
	int* list = *(int**)((char*)self + 0x3000
#if defined(jpn)
        + 0x50c
#else
        + 0x71c
#endif
);
	short id = *(short*)((char*)list + 0x22);
	GameState* bs = GameState::GetInstance();
	GameObject* c = bs->GetPartyMemberByIndex(id);
	if (c == NULL) {
		c = bs->GetProtagonist();
	}
	short val = *(short*)((char*)c + 4);
	EnqueueEventTag33_021d2738((unsigned char)(val & 0xff), param);
}
