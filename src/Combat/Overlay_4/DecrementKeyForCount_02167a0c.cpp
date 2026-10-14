#include <globaldefs.h>
#include "GameState/GameState.h"

int DecrementKeyEverywhere02086d88(unsigned char* self, int key);

// USA: func_ov004_02167a0c
ARM int DecrementKeyForCount_02167a0c(void* unused, int count) {
	unsigned char* p = (unsigned char*)GetPtrField0x2a04_02010828(GameState::GetInstance());
	int i;
	int v;
	for (i = 0; i < count; i++) {
		DecrementKeyEverywhere02086d88(p, 0x5617);
	}
	v = *(int*)(p + 0xf74) + count;
	v = (short)v;
	if (v > 0x1f4) {
		v = 0x1f4;
	}
	*(int*)(p + 0xf74) = v;
	return 0;
}
