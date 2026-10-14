#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);

// USA: func_ov001_0215f1b0
ARM int SetOrClearBitsFromField8_0215f1b0(void* self) {
	GameState::GetInstance();
	unsigned int* p = (unsigned int*)func_ov017_0218b5b0();
	int a = func_ov017_021d60f4(self);
	int b = func_ov017_021d60f4((char*)self + 0x8);
	if (b != 0) {
		SetBitsInField4_0203b4d8(p, a);
	} else {
		ClearBitsInField4_0203b4e8(p, a);
	}
	return 1;
}
