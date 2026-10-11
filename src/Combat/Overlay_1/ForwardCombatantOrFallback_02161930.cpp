#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021d6134(void*, int);
unsigned char GetField0x397cValue(GameState* battleStruct);

// USA: func_ov001_02161930
ARM int ForwardCombatantOrFallback_02161930(void* self) {
#if defined(jpn)
    enum { queueOffset = 0x524, idOffset = 0x12 };
#else
    enum { queueOffset = 0x734, idOffset = 0x16 };
#endif
	GameState* battle = GameState::GetInstance();
	char* p = (char*)func_ov017_0218b5b0() + 0x3000;
	char* table = *(char**)(p + queueOffset) + 0x100;
	int cid = *(signed char*)(table + idOffset);
	GameObject* c = GetCombatantWithFlag0x100(battle, cid);
	int n = cid;
	if (c == NULL) {
		n = GetField0x397cValue(battle);
	}
	func_ov017_021d6134(self, n);
	return 1;
}
