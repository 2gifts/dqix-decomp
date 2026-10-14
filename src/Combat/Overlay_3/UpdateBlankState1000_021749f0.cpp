#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#if defined(jpn)
enum { kRegion1041 = 0xfbd };
enum { kRegion1046 = 0xfc2 };
#else
enum { kRegion1041 = 0x1041 };
enum { kRegion1046 = 0x1046 };
#endif

// USA: func_ov003_021749f0  (semantic: UpdateBlankState1000_021749f0)
extern "C" ARM void func_ov003_021749f0(char* self) {
	if (!(*(unsigned short*)(self + kRegion1046) & 0x40)) {
		return;
	}
	unsigned char state = *(unsigned char*)(self + kRegion1041);
	if (state == 0) {
		FontBankLoader* g = GetGlobal02109400_02094a00();
		BlankFunction02094b34(g, 0x1fb, 0x66, 0, 0);
		*(unsigned char*)(self + kRegion1041) = *(unsigned char*)(self + kRegion1041) + 1;
	} else if (state == 1) {
		if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) != 0) {
			*(unsigned short*)(self + kRegion1046) &= ~0x40;
			*(unsigned char*)(self + kRegion1041) = 0;
		}
	}
}
