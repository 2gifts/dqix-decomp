#include <globaldefs.h>
#include "GameState/GameState.h"

struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase(void);
extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void func_02076a8c(void* obj);

struct EntryArg_0219e014 { unsigned char pad0[2]; unsigned short field2 : 2; unsigned short pad3 : 14; };

// USA: func_ov017_0219e014
ARM void ProcessEntryFlagsAndCombatants_0219e014(unsigned char* obj, EntryArg_0219e014* entry) {
	GameState* battleStruct = GameState::GetInstance();
	GetEntryTableBase();
	void* search = func_0202ae18();

	if (entry) {
		for (int i = 0; i < 0xc; i++) {
			unsigned int idx = entry->field2;
			int combatantId = i + (idx * 0xc + 0x70);
			GameObject* combatant = battleStruct->GetMaybeFieldMonsterByIndex(combatantId);

			if (combatant) {
				if (CheckField0NonZero((int*)search) && GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search) != 0) {
					func_02076a8c(combatant);
					((Object3D*)((unsigned char*)combatant))->MakeHidden();
				} else {
					((Object3D*)((unsigned char*)combatant))->Destroy();
				}
			}
		}
	}

	for (int i = 7; i <= 0x12; i++) {
		GameObject* combatant = battleStruct->GetGameObjectByIndex(i);
		if (combatant) {
			((Object3D*)combatant)->Initialize();
			((Object3D*)((unsigned char*)combatant))->MakeHidden();
		}
	}
}
