#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct OffsetTable02072e34;
void BuildOffsetTable02072e34(int n, struct OffsetTable02072e34* out);

extern int data_ov017_021d61c0[7];

// USA: func_ov017_021901ac
ARM void SetupCombatantAllocations_021901ac(void) {
	GameState* battleStruct = GameState::GetInstance();
	int table[11];
	for (int i = 0; i < 4; i++) {
		BuildOffsetTable02072e34(i, (struct OffsetTable02072e34*)table);
		for (int j = 0; j < 7; j++) {
			int id = table[data_ov017_021d61c0[j]];
			GameObject* combatant = battleStruct->GetGameObjectByIndex(id);
			if (combatant != NULL) {
				unsigned char* sub = *(unsigned char**)((char*)combatant + 8);
				if (sub != NULL) {
					((Model3D*)sub)->CreateBoneMatrixAndMaterialArrays(NULL, 0);
				}
			}
		}
	}
}
