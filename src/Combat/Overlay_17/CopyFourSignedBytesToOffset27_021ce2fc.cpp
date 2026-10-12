#include <globaldefs.h>

#if defined(jpn)
enum { kResourceTargetOffset = 0x3910 };
#else
enum { kResourceTargetOffset = 0x3b30 };
#endif


#if defined(jpn)
#define CopyFourSignedBytesToOffset27_021ce2fc func_ov017_021ce7a4
#endif

// USA: func_ov017_021ce2fc
#if defined(jpn)
extern "C"
#endif
ARM void CopyFourSignedBytesToOffset27_021ce2fc(int unused0, unsigned char* src, int unused2, unsigned char* ov) {
	unsigned char* dst = *(unsigned char**)(ov + kResourceTargetOffset);
	signed char* s = (signed char*)(src + 4);
	for (int i = 0; i < 4; i++) {
		*(signed char*)(dst + i + 0x1b) = s[i];
	}
}
