#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);

// KEEP-NAME
// USA: func_ov001_02156858
ARM int ReadByteAt17122_02156858(void*) {
	char* p = (char*)func_ov017_0218b5b0();
#if defined(jpn)
	return *(unsigned char*)(p + 0x40c2);
#else
	return *(unsigned char*)(p + 0x42e2);
#endif
}
