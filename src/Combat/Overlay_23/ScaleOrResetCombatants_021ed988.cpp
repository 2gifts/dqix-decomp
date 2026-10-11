#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct020372b8;
struct S02037418;
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(struct Struct020372b8* obj, int a, int b);
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(struct S02037418* obj, int val);
GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);

#if defined(jpn)
#define ALPHA_COUNT 0x701e
#define ALPHA_IDS 0x7020
#else
#define ALPHA_COUNT (0x6000 + 0xe2e)
#define ALPHA_IDS (0x6e00 + 0x30)
#endif

// JPN: func_ov023_021ed76c
// USA: func_ov023_021ed988
ARM void ScaleOrResetCombatants_021ed988(char *obj, int brightness) {
	GameState *bs = GameState::GetInstance();
	for (int i = 0; i < *(unsigned char*)(obj + ALPHA_COUNT); i++) {
		unsigned short *idxPtr = (unsigned short*)(obj + i * 2 + ALPHA_IDS);
		GameObject *combatant = GetCombatantWithFlag0x400(bs, *idxPtr);
		if (brightness > 0) {
			_ZN8Object3D24TransitionInheritedAlphaEii((struct Struct020372b8*)combatant, 0, brightness);
		} else {
			_ZN8Object3D17SetInheritedAlphaEi((struct S02037418*)combatant, 0);
		}
	}
}
