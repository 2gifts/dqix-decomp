#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x371c
#define REGION_OFFSET_1 0x47e
#else
#define REGION_OFFSET_0 0x3760
#define REGION_OFFSET_1 0x43e
#endif


extern "C" void* func_ov000_02161318(void* p0, int p1);

// USA: func_ov000_02162b70
ARM void SetByteField0x43eOnEntry(void* p, int key, unsigned char val) {
	void* entry = func_ov000_02161318((char*)p + REGION_OFFSET_0, key);
	if (entry != 0) {
		*((unsigned char*)entry + REGION_OFFSET_1) = val;
	}
}
