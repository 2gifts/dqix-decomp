#include <globaldefs.h>
#include "GameState/GameState.h"

struct Src_021d0d9c { unsigned char pad0[4]; int val; };

// USA: func_ov017_021d0d9c
ARM void StoreFieldIntoOffset2c94_021d0d9c(void* unused0, Src_021d0d9c* src, GameState* battleStruct) {
	unsigned char* p = (unsigned char*)GetPtrField0x2a04_02010828(battleStruct);
	*(int*)(p + 0x2000 + 0xc94) = src->val;
}
