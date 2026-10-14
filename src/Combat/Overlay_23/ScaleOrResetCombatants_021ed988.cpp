#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct020372b8;
struct S02037418;
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);

#if defined(jpn)
#define ALPHA_COUNT 0x701e
#define ALPHA_IDS 0x7020
#else
#define ALPHA_COUNT (0x6000 + 0xe2e)
#define ALPHA_IDS (0x6e00 + 0x30)
#endif

// USA: func_ov023_021ed988
ARM void ScaleOrResetCombatants_021ed988(char *obj, int brightness) {
	GameState *bs = GameState::GetInstance();
	for (int i = 0; i < *(unsigned char*)(obj + ALPHA_COUNT); i++) {
		unsigned short *idxPtr = (unsigned short*)(obj + i * 2 + ALPHA_IDS);
		GameObject *combatant = GetCombatantWithFlag0x400_0200fea4(bs, *idxPtr);
		if (brightness > 0) {
			((Object3D*)((struct Struct020372b8*)combatant))->TransitionInheritedAlpha(0, brightness);
		} else {
			((Object3D*)((struct S02037418*)combatant))->SetInheritedAlpha(0);
		}
	}
}
