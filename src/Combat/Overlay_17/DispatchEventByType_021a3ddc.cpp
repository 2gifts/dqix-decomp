#include <globaldefs.h>

struct S_021a185c;
void CallHelperIfByteAboveOneAndPtrSet_021a185c(S_021a185c* obj);

struct S021b8408;
void CallIfField6ac_021b8408(S021b8408* obj);

struct S021b6b44;
void CallIfField24_021b6b44(S021b6b44* obj);

void CallCallbackIfField1c_0217eedc(int* obj);

struct ObjWithField4_021afa9c;
void ForwardObjField4ToHandler_021afa9c(ObjWithField4_021afa9c* obj);

void CallField20PtrC_021c0520(void* obj);
void CallIfField1c_021c1208(void* obj);

struct Obj0217f230;
void CallIfFieldCSet_0217f230(Obj0217f230* obj);

void CallHelperIfFlag_021b1ce4(void*);
void NoOp_021b1fa4(void*);
void CallHelperIfFlagB_021b2328(void*);

// USA: func_ov017_021a3ddc  (semantic: DispatchEventByType_021a3ddc)
extern "C" ARM void func_ov017_021a3ddc(void* unused, void* obj) {
	if (!obj) return;
	if (*((unsigned char*)obj + 1) != 0) return;

	switch (*(signed char*)obj) {
	case 2:
		CallHelperIfByteAboveOneAndPtrSet_021a185c((S_021a185c*)obj);
		break;
	case 0xa:
		CallIfField6ac_021b8408((S021b8408*)obj);
		break;
	case 0x17:
		CallIfField24_021b6b44((S021b6b44*)obj);
		break;
	case 0x18:
		CallCallbackIfField1c_0217eedc((int*)obj);
		break;
	case 0x26:
		ForwardObjField4ToHandler_021afa9c((ObjWithField4_021afa9c*)obj);
		break;
	case 0x28:
		CallField20PtrC_021c0520(obj);
		break;
	case 0x29:
		CallIfField1c_021c1208(obj);
		break;
	case 0x2a:
		CallIfFieldCSet_0217f230((Obj0217f230*)obj);
		break;
	case 0x2b:
		CallHelperIfFlag_021b1ce4(obj);
		break;
	case 0x2c:
		NoOp_021b1fa4(obj);
		break;
	case 0x2d:
		CallHelperIfFlagB_021b2328(obj);
		break;
	}
}
