#include <globaldefs.h>

struct S0218c024 {
	char pad0[0x4];
	int flag4;      // 0x4
#if defined(jpn)
	char pad1[0xc - 0x8];
	int flag38;
	char pad2[0x30 - 0x10];
	int counter3c;
#else
	char pad1[0x38 - 0x8];
	int flag38;     // 0x38
	int counter3c;  // 0x3c
#endif
};

extern S0218c024 data_ov016_0219d0c0;

// USA: func_ov016_0218c024
ARM void SetFlagAndMaybeIncrement_0218c024(void) {
	data_ov016_0219d0c0.flag4 = 1;
	if (data_ov016_0219d0c0.flag38 == 0) data_ov016_0219d0c0.counter3c++;
}
