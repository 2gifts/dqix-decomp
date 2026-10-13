#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
enum { kRegionValue3EC_404 = 0x404 };
enum { kRegionValue3ED_405 = 0x405 };
enum { kRegionValue3F0_408 = 0x408 };
#else
enum { kRegionValue3EC_404 = 0x3ec };
enum { kRegionValue3ED_405 = 0x3ed };
enum { kRegionValue3F0_408 = 0x3f0 };
#endif



// USA: func_ov003_0215dc20  (semantic: AdvanceBlankStateCounter_0215dc20)
extern "C" ARM void func_ov003_0215dc20(void* obj) {
	unsigned char* o = (unsigned char*)obj;
	unsigned char state;
	FontBankLoader* g;
	if (o[kRegionValue3EC_404] == 0) return;
	state = o[kRegionValue3ED_405];
	if (state == 0) {
		g = GetGlobal02109400();
		BlankFunction02094b3c(g, 0xa);
		if (o[kRegionValue3F0_408] != 0) {
			BlankFunction02094b30(g, 0x1f5, 0);
		} else {
			BlankFunction02094b30(g, 0x200, 1);
		}
		o[kRegionValue3ED_405] = o[kRegionValue3ED_405] + 1;
		return;
	}
	if (state != 1) return;
	if (AlwaysTrue02094b4c(GetGlobal02109400()) != 0) {
		o[kRegionValue3EC_404] = 0;
		o[kRegionValue3ED_405] = 0;
	}
}
