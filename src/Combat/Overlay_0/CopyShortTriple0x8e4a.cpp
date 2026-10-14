#include <globaldefs.h>

// USA: func_ov000_0215fa84
ARM void CopyShortTriple0x8e4a_ov000_0215fa84(void* p, short* out0, short* out1, short* out2) {
	*out0 = *(short*)((char*)p + 0x8e4a);
	*out1 = *(short*)((char*)p + 0x8e4c);
	*out2 = *(short*)((char*)p + 0x8e4e);
}
