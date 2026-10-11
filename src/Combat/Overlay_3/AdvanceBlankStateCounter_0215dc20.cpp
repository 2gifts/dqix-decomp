#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue3EC_404 = 0x404 };
enum { kRegionValue3ED_405 = 0x405 };
enum { kRegionValue3F0_408 = 0x408 };
#else
enum { kRegionValue3EC_404 = 0x3ec };
enum { kRegionValue3ED_405 = 0x3ed };
enum { kRegionValue3F0_408 = 0x3f0 };
#endif


int GetGlobal02109400(void);
int AlwaysTrue02094b4c(void);
extern "C" void _Z21BlankFunction02094b3cv(int a, int b);
extern "C" void _Z21BlankFunction02094b30v(int a, int b, int c);

// USA: func_ov003_0215dc20  (semantic: AdvanceBlankStateCounter_0215dc20)
// JPN: func_ov003_0215ef68
extern "C" ARM void func_ov003_0215dc20(void* obj) {
	unsigned char* o = (unsigned char*)obj;
	unsigned char state;
	int g;
	if (o[kRegionValue3EC_404] == 0) return;
	state = o[kRegionValue3ED_405];
	if (state == 0) {
		g = GetGlobal02109400();
		_Z21BlankFunction02094b3cv(g, 0xa);
		if (o[kRegionValue3F0_408] != 0) {
			_Z21BlankFunction02094b30v(g, 0x1f5, 0);
		} else {
			_Z21BlankFunction02094b30v(g, 0x200, 1);
		}
		o[kRegionValue3ED_405] = o[kRegionValue3ED_405] + 1;
		return;
	}
	if (state != 1) return;
	GetGlobal02109400();
	if (AlwaysTrue02094b4c() != 0) {
		o[kRegionValue3EC_404] = 0;
		o[kRegionValue3ED_405] = 0;
	}
}
