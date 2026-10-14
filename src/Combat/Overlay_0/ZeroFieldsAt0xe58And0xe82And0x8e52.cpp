#include <globaldefs.h>

// USA: func_ov000_0215cd80
ARM void ZeroFieldsAt0xe58And0xe82And0x8e52_ov000_0215cd80(void* p) {
	*((unsigned char*)p + 0x8e82) = 0;
	*((unsigned char*)p + 0x8e83) = 0;
	*(unsigned short*)((char*)p + 0x8e52) = 0;
	*(int*)((char*)p + 0x8e58) = 0;
}
