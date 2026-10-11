#include <globaldefs.h>

extern "C" int func_ov031_02227bc8(void);
extern unsigned char data_ov031_02290cb0;
extern "C" void func_ov031_022368e0(void);
extern void ValidateAndProcessBuffer_02227c84(void);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02231724(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
extern void SetField18_02222e98(void);
extern "C" void func_ov031_0223193c(void);

// USA: func_ov031_02231864  (semantic: DispatchStateThenSetHandler_02231864)
extern "C" ARM void func_ov031_02231864(void) {
	int state = func_ov031_02227bc8();
	switch (state) {
	case 3:
		data_ov031_02290cb0 = 1;
		func_ov031_022368e0();
		ValidateAndProcessBuffer_02227c84();
		SetField_022274c0_022274c0((int)func_ov031_02231724);
		break;
	case 4:
		data_ov031_02290cb0 = 0;
		func_ov031_022368e0();
		func_ov031_02236878(9);
		func_ov031_02237b2c(0xd, 1, 1, -1, 0);
		SetField18_02222e98();
		SetField_022274c0_022274c0((int)func_ov031_0223193c);
		break;
	case 5:
		data_ov031_02290cb0 = 0;
		func_ov031_022368e0();
		func_ov031_02236878(0x12);
		func_ov031_02237b2c(0xe, 1, 1, -1, 0);
		SetField18_02222e98();
		SetField_022274c0_022274c0((int)func_ov031_0223193c);
		break;
	}
}
