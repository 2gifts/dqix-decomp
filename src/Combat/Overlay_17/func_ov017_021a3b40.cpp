#include <globaldefs.h>

void ResetField_021adc30_021adc30(void* obj);
void CallField1cIfFlagGt1_021a1880(void* obj);
extern "C" void func_ov017_021bb930(void* self);
void ForwardTeardownA_021b9904(char* p);
void CallField6acPtrA_021b8438(void* obj);
void CallIfGlobalPtrSet_021a5934(void);
void CallField20PtrA_021bae80(void* obj);
void CallField1cPtrA_021babc8(void* obj);
void CallCallbackIfField20Set_0217e580(int* obj);
void CallHelperIfFlag_021b2f0c(void);
struct S021b6b5c;
void CallIfField24_021b6b5c(S021b6b5c* obj);
void CallCallbackIfField1c_0217eec4(int* obj);
extern "C" void func_ov017_021aad8c(void* obj);
void BlankFunction_021accfc(void);
struct ObjWithField4_021afa70;
void CallField700ThenReset48_021afa70(ObjWithField4_021afa70* obj);
void CallField20PtrD_021c0538(void* obj);
void CallIfField1c_021c11f0(void* obj);
struct Obj0217f218;
void CallIfFieldCSet_0217f218(Obj0217f218* obj);
void CallHelperIfFlag_021b1cc4(void);
void NoOp_021b1fa0(void);
void CallHelperIfFlagB_021b2348(void);
void CallHelperIfFlag_021c162c(void);
void CallIfField20_021c19f8(void* obj);
void BlankFunction_021bef48(void);
void ResetField_021a9248_021a9248(void* obj);
struct S021a9998;
void CallIfField20_021a9998(S021a9998* obj);
void ResetField_021a7998_021a7998(void* obj);
struct Struct020dae68;
void ReleaseResource020dae68(Struct020dae68* obj);

// USA: func_ov017_021a3b40
extern "C" ARM void func_ov017_021a3b40(void* unused, void* obj) {
	if (!obj) return;
	if (*((unsigned char*)obj + 1) != 0) return;

	switch (*(signed char*)obj) {
	case 1:
		ResetField_021adc30_021adc30(obj);
		break;
	case 2:
		CallField1cIfFlagGt1_021a1880(obj);
		break;
	case 5:
		ForwardTeardownA_021b9904((char*)obj);
		break;
	case 0xa:
		CallField6acPtrA_021b8438(obj);
		break;
	case 0xc:
		((void (*)(void*))CallIfGlobalPtrSet_021a5934)(obj);
		break;
	case 0xf:
		CallField20PtrA_021bae80(obj);
		break;
	case 0x10:
		CallField1cPtrA_021babc8(obj);
		break;
	case 0x11:
		CallCallbackIfField20Set_0217e580((int*)obj);
		break;
	case 4:
		func_ov017_021bb930(obj);
		break;
	case 0x12:
		((void (*)(void*))CallHelperIfFlag_021b2f0c)(obj);
		break;
	case 0x17:
		CallIfField24_021b6b5c((S021b6b5c*)obj);
		break;
	case 0x18:
		CallCallbackIfField1c_0217eec4((int*)obj);
		break;
	case 0x1a:
		func_ov017_021aad8c(obj);
		break;
	case 0x1f:
		((void (*)(void*))BlankFunction_021accfc)(obj);
		break;
	case 0x26:
		CallField700ThenReset48_021afa70((ObjWithField4_021afa70*)obj);
		break;
	case 0x28:
		CallField20PtrD_021c0538(obj);
		break;
	case 0x29:
		CallIfField1c_021c11f0(obj);
		break;
	case 0x2a:
		CallIfFieldCSet_0217f218((Obj0217f218*)obj);
		break;
	case 0x2b:
		((void (*)(void*))CallHelperIfFlag_021b1cc4)(obj);
		break;
	case 0x2c:
		((void (*)(void*))NoOp_021b1fa0)(obj);
		break;
	case 0x2d:
		((void (*)(void*))CallHelperIfFlagB_021b2348)(obj);
		break;
	case 0x2e:
		((void (*)(void*))CallHelperIfFlag_021c162c)(obj);
		break;
	case 0x2f:
		CallIfField20_021c19f8(obj);
		break;
	case 0x34:
		((void (*)(void*))BlankFunction_021bef48)(obj);
		break;
	case 0x38:
		ResetField_021a9248_021a9248(obj);
		break;
	case 0x3a:
		CallIfField20_021a9998((S021a9998*)obj);
		break;
	case 0x3f:
		ResetField_021a7998_021a7998(obj);
		break;
	case 0x4b:
		ReleaseResource020dae68((Struct020dae68*)obj);
		break;
	}
}
