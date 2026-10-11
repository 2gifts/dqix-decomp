#include <globaldefs.h>
#if defined(jpn)
enum { kRegion1e0 = 0x1ec };
enum { kRegioncc = 0xca };
enum { kRegiond4 = 0xd0 };
enum { kRegionec = 0xe8 };
enum { kRegionee = 0xea };
enum { kRegioned = 0xe9 };
enum { kRegionef = 0xeb };
#else
enum { kRegion1e0 = 0x1e0 };
enum { kRegioncc = 0xcc };
enum { kRegiond4 = 0xd4 };
enum { kRegionec = 0xec };
enum { kRegionee = 0xee };
enum { kRegioned = 0xed };
enum { kRegionef = 0xef };
#endif

extern "C" int func_ov003_0217bdb8(void* p);

// JPN: func_ov003_021722d8
// USA: func_ov003_02173490
ARM void InitCombatFields_02173490(unsigned char* obj) {
	int ok = (func_ov003_0217bdb8(obj + kRegion1e0) != 0);
	if (!ok) return;
	obj[kRegioncc] = 1;
	obj[kRegiond4] = 0;
	obj[kRegionec] = 4;
	obj[kRegionee] = 0;
	obj[kRegioned] = 4;
	obj[kRegionef] = 0;
}
