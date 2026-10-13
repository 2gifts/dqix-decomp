#include <globaldefs.h>

extern int data_ov017_021d83ec;
#if defined(jpn)
#define func_ov006_021580b8 func_ov006_02159668
#endif
extern "C" void func_ov006_021580b8(void*);

// USA: func_ov017_021b1cc4
ARM void CallHelperIfFlag_021b1cc4(void*) {
	if (data_ov017_021d83ec != 0) {
		func_ov006_021580b8((void*)data_ov017_021d83ec);
	}
}
