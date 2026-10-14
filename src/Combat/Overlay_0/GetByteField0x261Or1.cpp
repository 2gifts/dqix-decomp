#include <globaldefs.h>

// USA: func_ov000_0216f0bc
ARM unsigned char GetByteField0x261Or1_ov000_0216f0bc(void* obj) {
	unsigned char* p = (unsigned char*)obj;
	if (p[0x260] != 0) {
		return p[0x261];
	}
	return 1;
}
