#include <globaldefs.h>

struct FlagPair_021b2348 { int a; int b; };
extern FlagPair_021b2348 data_ov017_021d83f0;
extern "C" void func_ov011_02184750(void);

// USA: func_ov017_021b2348
ARM void CallHelperIfFlagB_021b2348(void*) {
	if (data_ov017_021d83f0.b != 0) {
		func_ov011_02184750();
	}
}
