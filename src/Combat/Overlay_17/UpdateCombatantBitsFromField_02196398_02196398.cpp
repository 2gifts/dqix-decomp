#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
extern "C" void func_ov017_021973e8(void* obj);
unsigned int GetBitsInField4(unsigned int* obj, unsigned int mask);
extern "C" void func_ov017_0218e8c8(void* obj, unsigned int value, int mode);
extern "C" void func_ov017_021a1d98(void* obj, unsigned int value);

// USA: func_ov017_02196398
ARM void UpdateCombatantBitsFromField_02196398_02196398(unsigned int* obj) {
	GameState* battleStruct = GameState::GetInstance();
	GetField0x3b0Value(battleStruct);
	unsigned short value = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)battleStruct->GetProtagonist());
	func_ov017_021973e8(obj);

	if (!GetBitsInField4(obj, 4)) {
		func_ov017_0218e8c8(obj, value, 1);
	}
	if (!GetBitsInField4(obj, 0x10)) {
		func_ov017_021a1d98(obj, value);
	}
	if (!GetBitsInField4(obj, 4)) {
		func_ov017_0218e8c8(obj, value, 2);
	}
}
