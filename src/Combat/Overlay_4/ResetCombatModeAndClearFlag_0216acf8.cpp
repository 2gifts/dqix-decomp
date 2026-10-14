#include <globaldefs.h>
#include "Resource/GameResources.h"

void SetCombatModeFromCase020dc2d0(int mode);
void ClearFlags0xa97_02027bbc(unsigned char* base, int mask);

// USA: func_ov004_0216acf8  (semantic: ResetCombatModeAndClearFlag_0216acf8)
extern "C" ARM int func_ov004_0216acf8(void) {
	SetCombatModeFromCase020dc2d0(0);
	unsigned char* fieldObj = (unsigned char*)func_ov017_0218b5b0()->unknown_ptr_36d0;
	ClearFlags0xa97_02027bbc(fieldObj, 1);
	return 0;
}
