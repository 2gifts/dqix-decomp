#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xc8
#else
#define REGION_OFFSET_0 0x88
#endif


// USA: func_ov000_0217c4e8
ARM int IsBitFlagSet0217c4e8(void* obj, int idx) {
	unsigned char* base = (unsigned char*)obj + ((idx >> 3) & 0xff);
	unsigned char mask = (unsigned char)(1 << (idx & 7));
	return (base[REGION_OFFSET_0] & mask) != 0;
}
