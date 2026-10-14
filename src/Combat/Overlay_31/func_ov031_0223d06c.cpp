#include <globaldefs.h>

extern "C" void func_020cdbe4(void);
void WaitWhileFlagsSet_020ce0fc(int mask);
int GetMaskedStatus_020ce114(int mask);
extern "C" void func_ov031_0223cf70(void** slot);
extern void* data_ov031_02290d44;

// USA: func_ov031_0223d06c
extern "C" ARM void func_ov031_0223d06c(void) {
	int a = 4;
	int b = a;
	do {
		func_020cdbe4();
		WaitWhileFlagsSet_020ce0fc(a);
	} while (GetMaskedStatus_020ce114(b) != 0);
	func_ov031_0223cf70(&data_ov031_02290d44);
}
