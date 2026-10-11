#include <globaldefs.h>

// USA: func_ov017_0218d4b8
ARM void SetFlagBit_0218d4b8(unsigned char* base, int bit) {
	base += 0x4000;
#if defined(jpn)
	base[0x111] |= (1 << bit);
#else
	base[0x331] |= (1 << bit);
#endif
}
