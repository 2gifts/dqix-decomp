#include <globaldefs.h>

#if defined(jpn)
enum { kResourceTargetOffset = 0x34fc };
#else
enum { kResourceTargetOffset = 0x370c };
#endif


#if defined(jpn)
#define CopyHalfword4To24_021d23ec func_ov017_021d2870
#endif

struct SrcObj_021d23ec { unsigned char pad[4]; unsigned short h4; };
struct DstObj_021d23ec { unsigned char pad[0x24]; unsigned short h24; };

// USA: func_ov017_021d23ec
#if defined(jpn)
extern "C"
#endif
ARM void CopyHalfword4To24_021d23ec(int unused0, SrcObj_021d23ec* src, int unused2, unsigned char* ov) {
	DstObj_021d23ec* dst = *(DstObj_021d23ec**)(ov + kResourceTargetOffset);
	dst->h24 = src->h4;
}
