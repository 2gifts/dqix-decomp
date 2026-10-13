#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
extern "C" void func_02027428(unsigned char*, int);
#define ClearFlags0xa97 func_02027428
#endif

void SetCombatModeFromCase020dc2d0(int mode);
#if !defined(jpn)
void ClearFlags0xa97(unsigned char* base, int mask);
#endif

// USA: func_ov004_0216acf8  (semantic: ResetCombatModeAndClearFlag_0216acf8)
extern "C" ARM int func_ov004_0216acf8(void) {
	SetCombatModeFromCase020dc2d0(0);
	unsigned char* fieldObj = (unsigned char*)func_ov017_0218b5b0()->unknown_ptr_36d0;
	ClearFlags0xa97(fieldObj, 1);
	return 0;
}
