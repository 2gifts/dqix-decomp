#include <globaldefs.h>

extern "C" int func_ov031_0222fd9c(int idx);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_0222f38c(unsigned char id);
extern "C" void func_ov031_0222f3f8(unsigned char id);
extern "C" int func_ov031_02230ca4(void);
extern "C" int func_ov031_02230df0(void);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
extern "C" int func_ov031_022305a4(int a);
extern "C" void func_ov031_0222fe30(int, int, int);
extern "C" void func_ov031_02230120(void);
extern "C" void func_ov031_02230e90(void);
extern "C" void func_ov031_0222f68c(void);
void SetField1e_0223521c(void);
void SetField_022274c0_022274c0(int v);

extern unsigned char data_ov031_02249054;

struct HolderData0222f20c {
	unsigned char idx;
	unsigned char pad[7];
	unsigned char* ptr;
};
extern struct HolderData0222f20c data_ov031_02290ca0;

// USA: func_ov031_0222f20c  (semantic: DispatchByIdAndTransition_0222f20c)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0222f20c(int id) {
	if (func_ov031_0222fd9c(id) == 0) {
		func_ov031_02236878(9);
		return;
	}
	switch (id) {
	case 2:
	case 3:
		func_ov031_02236878(6);
		func_ov031_0222f38c((unsigned char)(((id - 2) ^ 1) != 0));
		return;
	case 7:
	case 8:
		func_ov031_02236878(6);
		func_ov031_0222f3f8((unsigned char)(((id - 7) ^ 1) != 0));
		return;
	default:
		data_ov031_02290ca0.ptr[0x40] = (unsigned char)id;
		if (id == 0xb || id == 0xc) {
			func_ov031_02230ca4();
			if (func_ov031_02230df0() == 0) {
				func_ov031_02236878(9);
				func_ov031_02237b2c(6, 1, 1, -1, 0);
				SetField_022274c0_022274c0((int)func_ov031_02230e90);
				return;
			}
			if (id == 0xb) func_ov031_02236878(6);
			else func_ov031_02236878(0xe);
		} else if (id == 0xd) {
			func_ov031_02230ca4();
			func_ov031_02236878(7);
		} else {
			func_ov031_02236878(6);
			unsigned char v = (&data_ov031_02249054)[id];
			int r = func_ov031_022305a4(v);
			func_ov031_0222fe30(0, 1, r);
			func_ov031_02230120();
		}
		SetField1e_0223521c();
		SetField_022274c0_022274c0((int)func_ov031_0222f68c);
		return;
	}
}
