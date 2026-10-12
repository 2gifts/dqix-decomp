#include <globaldefs.h>
#if defined(jpn)
#define func_ov004_0216acf8 func_ov004_0216af54
enum { FieldObjectOffset0216acf8 = 0x4c0 };
extern "C" void func_02027428(unsigned char*, int);
#define ClearFlags0xa97 func_02027428
#else
enum { FieldObjectOffset0216acf8 = 0x6d0 };
#endif

void SetCombatModeFromCase020dc2d0(int mode);
extern "C" struct AxisFloats0203b5f8* func_ov017_0218b5b0(void);
#if !defined(jpn)
void ClearFlags0xa97(unsigned char* base, int mask);
#endif

// USA: func_ov004_0216acf8  (semantic: ResetCombatModeAndClearFlag_0216acf8)
extern "C" ARM int func_ov004_0216acf8(void) {
	SetCombatModeFromCase020dc2d0(0);
	unsigned char* fieldObj = *(unsigned char**)((char*)func_ov017_0218b5b0() + 0x3000 + FieldObjectOffset0216acf8);
	ClearFlags0xa97(fieldObj, 1);
	return 0;
}
