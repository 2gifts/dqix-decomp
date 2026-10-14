#include <globaldefs.h>

extern "C" void* func_0205ec34(void);
extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov017_021d6134(void* param, int val);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);

// USA: func_ov001_021632e4
ARM int NotifyBitTestResult_021632e4(void* param) {
	void* base = func_0205ec34();
	int id = func_ov017_021d60f4(param);
	int bit = TestBitInByteArray_0206dfb0((int)base, (unsigned char*)base + 0x8c, id);
	if (bit != 0) {
		func_ov017_021d6134((char*)param + 8, 1);
	} else {
		func_ov017_021d6134((char*)param + 8, 0);
	}
	return 1;
}
