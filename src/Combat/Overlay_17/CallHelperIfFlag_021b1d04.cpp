#include <globaldefs.h>

extern int data_ov017_021d83ec;
extern "C" void func_ov006_02158478(void);

// USA: func_ov017_021b1d04
ARM void CallHelperIfFlag_021b1d04(void*) {
	if (data_ov017_021d83ec != 0) {
		func_ov006_02158478();
	}
}
