#include <globaldefs.h>
#if defined(jpn)
#define FLAGS_OFFSET (0x500 + 0x6c)
#else
#define FLAGS_OFFSET (0x600 + 0x34)
#endif

// USA: func_ov023_021e338c
ARM void SetFlagt_021e338c_021e338c(char* p) {
	unsigned short* flags = (unsigned short*)(p + FLAGS_OFFSET);
	*flags = *flags | 0x1000;
}
