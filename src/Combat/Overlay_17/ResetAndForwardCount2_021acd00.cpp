#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);
void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(void* a, int b);

// USA: func_ov017_021acd00
ARM void ResetAndForwardCount2_021acd00(void*) {
	void* x = (void*)GetGlobalField0x1c020421a0();
	Forward0204359c(x, 2);
	func_020439b0(x, 0);
}
