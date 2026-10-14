#include <globaldefs.h>

// USA: func_ov000_0215e918
ARM void* GetTableEntry0x8e00Bound0x48_ov000_0215e918(void* p) {
	unsigned char idx = *((unsigned char*)p + 0x8e00);
	if (idx >= 0x48) {
		return 0;
	}
	return (char*)p + 0x20 + idx * 0x34;
}
