#include <globaldefs.h>

#if defined(jpn)
static const int kBufferOffset = 0x4208;
#else
static const int kBufferOffset = 0x44b8;
#endif

// USA: func_ov017_02197324
ARM void ClearMatchingHalfword_02197324(unsigned char* obj, unsigned short key) {
	unsigned short* p = (unsigned short*)(obj + kBufferOffset);
	for (int i = 0; i < 4; i++, p++) {
		if (*p == key) {
			*p = 0;
			return;
		}
	}
}
