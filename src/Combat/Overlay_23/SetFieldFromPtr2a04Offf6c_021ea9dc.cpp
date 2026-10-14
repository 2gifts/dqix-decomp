#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021ea9dc
ARM int SetFieldFromPtr2a04Offf6c_021ea9dc(void* obj) {
	GameState* bs = GameState::GetInstance();
	void* p = GetPtrField0x2a04_02010828(bs);
	int v = *(int*)((char*)p + 0xf6c);
	func_ov017_021d6134(obj, v);
	return 1;
}
