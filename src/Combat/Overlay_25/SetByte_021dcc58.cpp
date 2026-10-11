#include <globaldefs.h>

#if defined(jpn)
enum { ByteBase = 0x7000, ByteOffset = 0x3b };
#else
enum { ByteBase = 0x6000, ByteOffset = 0xe4b };
#endif

// USA: func_ov025_021dcc58
ARM void SetByte_021dcc58(void* obj, unsigned char v) {
	unsigned char* base = (unsigned char*)obj;
	(base + ByteBase)[ByteOffset] = v;
}
