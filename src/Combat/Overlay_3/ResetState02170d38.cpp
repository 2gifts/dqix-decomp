#include <globaldefs.h>
#if defined(jpn)
enum { kRegion4494 = 0x41e4 };
#else
enum { kRegion4494 = 0x4494 };
#endif


extern "C" void func_0202ae18();
extern "C" void func_0202b0f4();
extern "C" void* func_ov017_0218b5b0();
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);

// JPN: func_ov003_021703f4
// USA: func_ov003_02170d38
ARM void ResetState02170d38(void) {
	func_0202ae18();
	func_0202b0f4();
	*(int*)((char*)func_ov017_0218b5b0() + kRegion4494) = 0;
	unsigned int* p = (unsigned int*)func_ov017_0218b5b0();
	ClearBitsInField4(p, 2);
	ClearBitsInWord(p, 4);
	func_ov017_0219bd1c(1, 0, 0, 0);
}
