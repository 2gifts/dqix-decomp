#include <globaldefs.h>

struct FlagPair_021b2368 { int a; int b; };
extern FlagPair_021b2368 data_ov017_021d83f0;
extern "C" void func_ov011_02184760(void);

// USA: func_ov017_021b2368
ARM void CallHelperIfFlagB_021b2368(void) {
	if (data_ov017_021d83f0.b != 0) {
		func_ov011_02184760();
	}
}
