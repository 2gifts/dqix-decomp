#include <globaldefs.h>

extern "C" unsigned char* func_ov017_0219219c(void);

// USA: func_ov017_02191b58
ARM int GetByteAtPtrOrZero_02191b58(void*, int) {
	unsigned char* p = func_ov017_0219219c();
	return p ? *p : 0;
}
