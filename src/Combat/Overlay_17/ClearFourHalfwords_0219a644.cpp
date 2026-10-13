#include <globaldefs.h>

// USA: func_ov017_0219a644
ARM void ClearFourHalfwords_0219a644(void* obj, int) {
	unsigned char i;
	for (i = 0; i < 4; i++) {
		*(short*)((char*)obj + i * 0xe0 +
#if defined(jpn)
        0x3b96
#else
        0x3db6
#endif
        ) = 0;
	}
}
