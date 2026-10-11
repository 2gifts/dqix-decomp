#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void _ZN8Object3D19SetAlphaScaleFactorEi(unsigned char* obj, short value);

extern int data_ov017_021d6298[14];

// USA: func_ov017_021919c8
ARM void SetGroupShortValues_021919c8(int unusedA, int b, short c) {
	int table[14];
	struct Whole_021919c8 { int v[14]; };
	*(struct Whole_021919c8*)table = *(struct Whole_021919c8*)data_ov017_021d6298;
	int base = b * 12;
	table[0] = b;
	table[1] = base + 0x13;
	table[2] = base + 0x14;
	table[3] = base + 0x15;
	table[4] = base + 0x16;
	table[5] = base + 0x17;
	table[6] = base + 0x18;
	table[7] = base + 0x19;
	table[8] = base + 0x1a;
	table[9] = base + 0x1b;
	table[10] = base + 0x1c;
	table[11] = base + 0x1d;
	GameState* battleStruct = GameState::GetInstance();
	for (int i = 0; table[i] > -1; i++) {
		GameObject* combatant = battleStruct->GetGameObjectByIndex(table[i]);
		if (combatant) {
			_ZN8Object3D19SetAlphaScaleFactorEi((unsigned char*)combatant, c);
		}
	}
}
