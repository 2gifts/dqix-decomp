#include <globaldefs.h>

extern "C" char* func_ov017_0218b5b0(void);

// USA: func_ov001_0215fef4
ARM int ClearGlobalField1584_0215fef4(void) {
#if defined(jpn)
    enum { fieldOffset = 0x420 };
#else
    enum { fieldOffset = 0x630 };
#endif
	*(int*)((func_ov017_0218b5b0() + 0x3000) + fieldOffset) = 0;
	return 1;
}
