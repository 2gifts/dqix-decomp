#include <globaldefs.h>

extern int data_02114e30;
extern unsigned char data_02114e54;
struct Obj0205eaa0;
extern struct Obj0205eaa0 data_02108760;

extern "C" int _Z25TestFlag0SetAndFlag1ClearPti(int* flags, int mask);
extern "C" int _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);

// USA: func_ov023_021ed014
ARM int DispatchIfFlagsOrByteSet_021ed014(struct GuideWindow_021ec480* window) {
	if (_Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 0xf03) == 0 && *((unsigned char*)&data_02114e54 + 0x55) == 0) {
		return 0;
	}
	_Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
	return 1;
}
