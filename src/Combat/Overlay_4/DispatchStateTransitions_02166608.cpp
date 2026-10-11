#include <globaldefs.h>

extern "C" void func_ov023_021f645c(void* a, int b, unsigned short c, int d);
int DispatchNodeIfState6_021f6680(void* obj, int id);

struct Root02166608 {
	char pad[0x50];
	unsigned char loFlags : 6;
	unsigned char bit6 : 1;
	unsigned char bit7 : 1;
};
extern struct Root02166608* data_ov004_0217101c;

#if defined(jpn)
enum { globalPointerIndex = 1 };
#else
enum { globalPointerIndex = 0 };
#endif

// USA: func_ov004_02166608
// JPN: func_ov004_02166bf4
ARM void DispatchStateTransitions_02166608(void* a) {
	struct Root02166608* r = (&data_ov004_0217101c)[globalPointerIndex];
	func_ov023_021f645c(a, 0xaa, r->bit6 + 1, 0xf);
	DispatchNodeIfState6_021f6680(a, 0x15);
	func_ov023_021f645c(a, 0xa0, r->bit7 + 3, 0xf);
	DispatchNodeIfState6_021f6680(a, 0x16);
}
