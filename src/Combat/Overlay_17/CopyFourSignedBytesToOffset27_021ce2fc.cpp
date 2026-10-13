#include <globaldefs.h>
#include "Resource/GameResources.h"

// USA: func_ov017_021ce2fc
ARM void CopyFourSignedBytesToOffset27_021ce2fc(int unused0, unsigned char* src, int unused2, unsigned char* ov) {
	unsigned char* dst = (unsigned char*)((GameResources*)ov)->unknown_ptr_array_3afc[13];
	signed char* s = (signed char*)(src + 4);
	for (int i = 0; i < 4; i++) {
		*(signed char*)(dst + i + 0x1b) = s[i];
	}
}
