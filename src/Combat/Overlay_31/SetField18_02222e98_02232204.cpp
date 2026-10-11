#include <globaldefs.h>

extern "C" void func_ov031_022368e0(void);
extern "C" int func_ov031_02235984(void**);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
extern "C" int func_ov031_02236878(int);
ARM void SetField18_02222e98(void);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_022324bc(void);
extern "C" void func_ov031_02232380(void);

struct State02290cbc_02232204 { unsigned char state; unsigned char pad; unsigned short counter; };
extern State02290cbc_02232204 data_ov031_02290cbc;

// USA: func_ov031_02232204
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02232204(void) {
	data_ov031_02290cbc.counter++;
	if (data_ov031_02290cbc.counter < 300) {
		return;
	}

	func_ov031_022368e0();
	void* out;
	int count = func_ov031_02235984(&out);
	if (count == 0) {
		data_ov031_02290cbc.state = 2;
		func_ov031_02237b2c(0xf, 1, 1, -1, 0);
		func_ov031_02236878(0x12);
		SetField18_02222e98();
		SetField_022274c0_022274c0((int)func_ov031_022324bc);
		return;
	}

	int matched = 0;
	if (count > 0) {
		unsigned char* p = (unsigned char*)out;
		do {
			if (p[0x28] != 2) {
				break;
			}
			matched++;
			p += 0x2a;
		} while (matched < count);
	}

	if (matched == count) {
		data_ov031_02290cbc.state = 3;
		func_ov031_02237b2c(0xe, 1, 1, -1, 0);
		func_ov031_02236878(0x12);
		SetField18_02222e98();
		SetField_022274c0_022274c0((int)func_ov031_022324bc);
		return;
	}

	data_ov031_02290cbc.state = 1;
	func_ov031_02236878(0xf);
	SetField_022274c0_022274c0((int)func_ov031_02232380);
}
