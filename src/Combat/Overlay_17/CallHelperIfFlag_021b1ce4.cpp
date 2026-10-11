#include <globaldefs.h>

extern int data_ov017_021d83ec;
#if defined(jpn)
#define func_ov001_02158038 func_ov006_02158038
#endif
extern "C" void func_ov001_02158038(void*);

// USA: func_ov017_021b1ce4
ARM void CallHelperIfFlag_021b1ce4(void) {
	if (data_ov017_021d83ec != 0) {
		func_ov001_02158038((void*)data_ov017_021d83ec);
	}
}
