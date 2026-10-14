#include <globaldefs.h>

// USA: func_ov000_02161bec
ARM void IncrementByteCounterWrapAt0x12_ov000_02161bec(unsigned char* p) {
	int v = *p;
	v = v + 1;
	*p = v;
	if ((unsigned)(v & 0xff) >= 0x12) {
		*p = 1;
	}
}
