#include <globaldefs.h>

struct S0218d294 {
	int flag0;      // 0x0
	#if defined(jpn)
 char pad0[0x10 - 0x4];
#else
 char pad0[0x14 - 0x4];
#endif
	int flag14;     // 0x14
	int counter18;  // 0x18
};

extern S0218d294 data_ov016_0219d144;

// USA: func_ov016_0218d294
ARM void SetFlagAndMaybeIncrement_0218d294(void) {
	data_ov016_0219d144.flag0 = 1;
	if (data_ov016_0219d144.flag14 == 0) data_ov016_0219d144.counter18++;
}
