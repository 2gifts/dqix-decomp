#include <globaldefs.h>

#if defined(jpn)
enum { kResourceWorkOffset = 0x3508 };
#else
enum { kResourceWorkOffset = 0x3718 };
#endif


#if defined(jpn)
#define DispatchWithHalfwords_021ca2d8 func_ov017_021ca788
#endif

struct SrcObj_021ca2d8 { unsigned char pad[4]; unsigned short h4; unsigned short h6; };

extern "C" int func_ov017_021b88d0(int, unsigned short, unsigned short);

// USA: func_ov017_021ca2d8
#if defined(jpn)
extern "C"
#endif
ARM int DispatchWithHalfwords_021ca2d8(int unused0, SrcObj_021ca2d8* src, int unused2, unsigned char* ov) {
	int val = *(int*)(ov + kResourceWorkOffset);
	return func_ov017_021b88d0(val, src->h4, src->h6);
}
