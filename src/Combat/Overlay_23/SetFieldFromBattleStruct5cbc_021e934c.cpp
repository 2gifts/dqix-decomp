#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField5cbcValue_0201081c(char* obj);
extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021e934c
ARM int SetFieldFromBattleStruct5cbc_021e934c(void* obj) {
	GameState* bs = GameState::GetInstance();
	int v = GetField5cbcValue_0201081c((char*)bs);
	func_ov017_021d6134(obj, v);
	return 1;
}
