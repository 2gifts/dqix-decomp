#include <globaldefs.h>

struct Data02248eb4 {
	unsigned char pad[8];
	int field8;
	int fieldC;
};

extern struct Data02248eb4 data_ov031_02248eb4;
extern void* data_ov031_02290c94;

extern int IsField11cPtrSet_02223fdc(void);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222d1b8(void);
extern "C" int func_ov031_02237b2c(int, int, int, int, int);
extern void AdvanceUnlessField1bActive_0222d6b0(void);
extern void GetFields181c_02227520(int*, int*);
extern "C" void func_ov031_0222d418(void);

// USA: func_ov031_0222d0e0
#pragma optimize_for_size off
ARM void DispatchByField2aByte_0222d0e0(void) {
	int arr[2];
	arr[0] = data_ov031_02248eb4.field8;
	arr[1] = data_ov031_02248eb4.fieldC;

	if (IsField11cPtrSet_02223fdc() != 0) return;

	unsigned char v = *((unsigned char*)data_ov031_02290c94 + 0x2a);
	if (v == 0) {
		SetField_022274c0_022274c0((int)func_ov031_0222d1b8);
		return;
	}
	if (v == 2) {
		func_ov031_02237b2c(6, 3, 1, -1, 0);
		SetField_022274c0_022274c0((int)AdvanceUnlessField1bActive_0222d6b0);
		return;
	}

	int idx;
	GetFields181c_02227520(NULL, &idx);
	func_ov031_02237b2c(arr[idx], 2, 1, -1, 0);
	SetField_022274c0_022274c0((int)func_ov031_0222d418);
}
