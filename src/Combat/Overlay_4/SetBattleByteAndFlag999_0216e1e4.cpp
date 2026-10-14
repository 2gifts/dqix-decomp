#include <globaldefs.h>
#include "GameState/GameState.h"

void SetByte0x7f70_02012028(void* obj, unsigned char value);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216e1e4  (semantic: SetBattleByteAndFlag999_0216e1e4)
extern "C" ARM int func_ov004_0216e1e4(void* obj) {
	GameState* battle = GameState::GetInstance();
	SetByte0x7f70_02012028(battle, 1);
	func_ov011_021848a0(obj, 0x3e7);
	return 0;
}
