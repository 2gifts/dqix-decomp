#include <globaldefs.h>

#if defined(jpn)
#define SetFieldFromPercentOver232_021e9a10 func_ov023_021e9974
#endif

int LoadBattleBlock020ac4c0(void* dst);

struct S_a08a4 {
	char pad[0x14];
	unsigned int a : 9;
	unsigned int val : 9;
	unsigned int hi : 14;
};
int GetFieldPercentOver232(struct S_a08a4* p);

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9a10
#if defined(jpn)
extern "C"
#endif
ARM int SetFieldFromPercentOver232_021e9a10(void* obj) {
	unsigned char buf[0xb0];
	LoadBattleBlock020ac4c0(buf);
	int pct = GetFieldPercentOver232((struct S_a08a4*)buf);
	func_ov017_021d6134(obj, pct);
	return 1;
}
