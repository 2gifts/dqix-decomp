#include <globaldefs.h>

extern "C" int func_ov031_02227bc8(void);
extern unsigned char data_ov031_02290cac;
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0223130c(void);
extern "C" void func_ov031_022368e0(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
extern void SetField18_02222e98(void);
extern "C" void func_ov031_022314ec(void);

// USA: func_ov031_02231468  (semantic: DispatchStateThenSetHandler_02231468)
extern "C" ARM void func_ov031_02231468(void) {
	int state = func_ov031_02227bc8();
	switch (state) {
	case 2:
		data_ov031_02290cac = 1;
		SetField_022274c0_022274c0((int)func_ov031_0223130c);
		break;
	case 4:
		data_ov031_02290cac = 0;
		func_ov031_022368e0();
		func_ov031_02236878(9);
		func_ov031_02237b2c(0xd, 1, 1, -1, 0);
		SetField18_02222e98();
		SetField_022274c0_022274c0((int)func_ov031_022314ec);
		break;
	}
}
