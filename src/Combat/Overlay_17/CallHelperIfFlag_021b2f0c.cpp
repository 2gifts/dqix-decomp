#include <globaldefs.h>

extern int data_ov017_021d840c;
extern "C" void func_ov003_0217480c(void);

// USA: func_ov017_021b2f0c
ARM void CallHelperIfFlag_021b2f0c(void*) {
	if (data_ov017_021d840c != 0) {
		func_ov003_0217480c();
	}
}
