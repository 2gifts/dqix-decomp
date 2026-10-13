#include <globaldefs.h>
#include "Resource/GameResources.h"


#if defined(jpn)
#define CopyByteIfFlagMatches_021cc1d8 func_ov017_021cc680
#endif

struct Src_021cc1d8 { unsigned char pad0[4]; unsigned char flagByte; unsigned char pad1[3]; int val; };
struct Tgt_021cc1d8 { unsigned char pad[0xf]; unsigned char outByte; signed char cmpByte; };

// USA: func_ov017_021cc1d8
#if defined(jpn)
extern "C"
#endif
ARM void CopyByteIfFlagMatches_021cc1d8(int unused0, Src_021cc1d8* src, int unused2, unsigned char* base) {
	Tgt_021cc1d8* tgt = (Tgt_021cc1d8*)((GameResources*)base)->unknown_ptr_array_3afc[12];
	if (tgt->cmpByte == src->flagByte) {
		tgt->outByte = (unsigned char)src->val;
	}
}
