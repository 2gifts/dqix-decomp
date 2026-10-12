#include <globaldefs.h>

#if defined(jpn)
enum { kResourceWorkOffset = 0x3508, kWorkByteOffset = 0xe30 };
#else
enum { kResourceWorkOffset = 0x3718, kWorkByteOffset = 0xeb4 };
#endif


#if defined(jpn)
#define CopyByte4ToOffsetEb4_021c9d08 func_ov017_021ca1b8
#endif

extern "C" void* func_ov017_021b8468(void*);

// USA: func_ov017_021c9d08
#if defined(jpn)
extern "C"
#endif
ARM void CopyByte4ToOffsetEb4_021c9d08(void* unused0, void* src, void* unused2, void* obj) {
	void* dst = func_ov017_021b8468(*(void**)((char*)obj + kResourceWorkOffset));
	if (dst) {
		*((unsigned char*)dst + kWorkByteOffset) = *((unsigned char*)src + 0x4);
	}
}
