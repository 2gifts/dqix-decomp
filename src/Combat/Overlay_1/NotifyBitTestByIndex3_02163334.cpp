#include <globaldefs.h>

extern "C" void* func_0205ec34(void);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov017_021d6134(void* param, int val);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);

// USA: func_ov001_02163334
ARM int NotifyBitTestByIndex3_02163334(void* param) {
	unsigned char* base = (unsigned char*)func_0205ec34();
	int id = func_ov017_021d60f4(param);
	int idx = base[0x332];
	int bit = TestBitInByteArray_0206dfb0((int)base, base + idx * 0x1c + 3, id);
	if (bit != 0) {
		func_ov017_021d6134((char*)param + 8, 1);
	} else {
		func_ov017_021d6134((char*)param + 8, 0);
	}
	return 1;
}
