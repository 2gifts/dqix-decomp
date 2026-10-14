#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" int func_020cd908(void* p);
extern "C" void func_020cd99c(void* p);
extern "C" void func_020c9be0(void);
extern "C" void func_020cdae4(int a, int b, int c, int d);
void WaitWhileFlagsSet_020ce0fc(int mask);
int GetMaskedStatus_020ce114(int mask);
void RunTwoStepUpdate_0223d0a4();

struct Outer_0223cff0 { unsigned char pad0[4]; void* inner; };
extern struct Outer_0223cff0 data_ov031_02290d40;

// USA: func_ov031_0223cff0  (semantic: AllocAndInitTwoStepState_0223cff0)
extern "C" ARM void func_ov031_0223cff0(void) {
	data_ov031_02290d40.inner = func_ov031_0223cf4c(0x3a, 4);

	unsigned char buf[8];
	if (func_020cd908(buf) == 0) {
		func_020c9be0();
	}
	func_020cd99c(buf);

	func_020cdae4(0, 4, (int)data_ov031_02290d40.inner, 5);
	WaitWhileFlagsSet_020ce0fc(2);
	if (GetMaskedStatus_020ce114(2) != 0) {
		func_020c9be0();
	}
	RunTwoStepUpdate_0223d0a4();
}
