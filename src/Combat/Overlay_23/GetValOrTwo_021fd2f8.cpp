#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

struct S_021fd2f8 { char pad[0x1c]; int val; };

// USA: func_ov023_021fd2f8
ARM int GetValOrTwo_021fd2f8(struct S_021fd2f8* s) {
	if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) != 0) return 2;
	return s->val;
}
