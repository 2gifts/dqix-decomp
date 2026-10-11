// JPN: func_ov017_021927a4
#if defined(jpn)
enum { RegionOffset370c = 0x34fc, RegionOffset9c = 0x1ec, RegionOffset4400 = 0x4000 };
#else
enum { RegionOffset370c = 0x370c, RegionOffset9c = 0x9c, RegionOffset4400 = 0x4400 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void _Z21ClearFieldBit02053fe4P9T02053fe4(void* obj, int field2, int flag);
extern "C" int _ZNK8Object3D7GetFlagEi(void* obj, int mask);
void* GetField0x3f8Address(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);

extern "C" void func_ov017_021c9e00(int i, int one1, int zero, int one2);

// USA: func_ov017_02191bdc
ARM void ClearMonsterFlagEntries_02191bdc(unsigned char* a, int b) {
	GameState* battleStruct = GameState::GetInstance();
	GameObject* combatant = battleStruct->GetUnknownGameObject();
	if (!combatant) return;
	if (*(short*)((char*)combatant + 0xac) != 0) return;
	if (_ZNK8Object3D7GetFlagEi(combatant, 0x8000000) != 0) return;
	if (b == 0) {
		unsigned char* fieldAddr = (unsigned char*)GetField0x3f8Address(battleStruct);
		unsigned char* q = *(unsigned char**)(a + RegionOffset370c);
		if (q[2] != 0) return;
		if (fieldAddr[2] != 0) return;
	}
	unsigned char* entry = a + RegionOffset9c + RegionOffset4400;
	for (int i = 0; i < 4; entry += 4, i++) {
		if (entry[0] == 0) continue;
		GameObject* c2 = GetCombatantWithFlag0x100(battleStruct, i);
		if (c2 != NULL) {
			_Z21ClearFieldBit02053fe4P9T02053fe4(c2, *(short*)(entry + 2), 1);
			func_ov017_021c9e00(i, 1, 0, 1);
		}
		entry[0] = 0;
		*(short*)(entry + 2) = 0;
	}
}
