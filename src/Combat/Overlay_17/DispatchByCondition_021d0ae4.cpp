#include <globaldefs.h>

#if defined(jpn)
#define DispatchByCondition_021d0ae4 func_ov017_021d0f94
#endif

extern "C" int func_0202c508(int p);
extern "C" void func_ov017_02192654(int a0, unsigned short f4, unsigned char f6);
extern "C" void func_ov017_021a23b0(int a3, unsigned short f4);

struct Obj021d0ae4 {
	unsigned char pad0[4];
	unsigned short f4;
	unsigned char f6;
};

// USA: func_ov017_021d0ae4
#if defined(jpn)
extern "C"
#endif
ARM void DispatchByCondition_021d0ae4(int a0, Obj021d0ae4* obj, int unused2, int a3, int arg5) {
	if (func_0202c508(arg5) != 0) {
		func_ov017_02192654(a0, obj->f4, obj->f6);
		return;
	}
	if (a0 != 0) {
		return;
	}
	func_ov017_021a23b0(a3, obj->f4);
}
