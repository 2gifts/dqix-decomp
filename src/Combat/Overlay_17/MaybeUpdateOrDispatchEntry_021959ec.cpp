#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

int GetFlags(int obj);
void UpdateEntry0216d50c(void* work);
extern "C" void func_0202e0a4(int val);

// USA: func_ov017_021959ec
ARM void MaybeUpdateOrDispatchEntry_021959ec(void) {
	GameState* bs = GameState::GetInstance();
	void* val = GetField0x3b0Value(bs);
	if (val == 0) return;
	if (GetFlags((int)val) & 8) {
		UpdateEntry0216d50c(val);
	} else {
		func_0202e0a4((int)val);
	}
}
