#include <globaldefs.h>

extern "C" int _Z20GetField11c_02223fa0v(void);
extern "C" void _Z20SetField123_02223fb4i(int);
extern "C" void _Z20SetField124_02223fc8i(int);
ARM void SetField_022274c0_022274c0(int);
extern "C" int func_ov031_02236878(int);
extern "C" int func_ov031_0222d524(void);
extern "C" void func_ov031_0222d2bc(void);
extern "C" void func_ov031_0222d3b0(void);
extern "C" void _Z22SetupHandlerA_0222d094v(void);

struct Struct0222ced0 {
	unsigned char pad0[4];
	int* field4;
	unsigned char pad8[0x29 - 8];
	unsigned char field29;
	unsigned char field2a;
};
extern Struct0222ced0* data_ov031_02290c94;

// USA: func_ov031_0222ced0
// JPN: func_ov031_0222d6b0
extern "C" ARM void func_ov031_0222ced0(void) {
	int v = _Z20GetField11c_02223fa0v();
	switch (v) {
	case 0:
		goto epilogueA;
	case 0x80:
		if (data_ov031_02290c94->field29 != 0) {
			func_ov031_02236878(3);
			data_ov031_02290c94->field29 -= 1;
			{
				unsigned char* rec = (unsigned char*)data_ov031_02290c94 + data_ov031_02290c94->field29;
				rec[8] = 0;
			}
			if (data_ov031_02290c94->field29 == 0) {
				_Z20SetField123_02223fb4i(0);
			}
			_Z20SetField124_02223fc8i(1);
		}
		goto epilogueA;
	case 0x82:
		func_ov031_02236878(7);
		data_ov031_02290c94->field2a = 0;
		SetField_022274c0_022274c0((int)_Z22SetupHandlerA_0222d094v);
		return;
	case 0x83:
		if (func_ov031_0222d524()) {
			func_ov031_02236878(6);
			data_ov031_02290c94->field2a = 1;
		} else {
			data_ov031_02290c94->field2a = 2;
			func_ov031_02236878(9);
		}
		*(data_ov031_02290c94->field4) = (*(data_ov031_02290c94->field4) & 0xc1fffcff) | 0x200;
		SetField_022274c0_022274c0((int)_Z22SetupHandlerA_0222d094v);
		return;
	case 0xe01d:
	default:
		if (data_ov031_02290c94->field29 != 0x20) {
			func_ov031_02236878(1);
			{
				unsigned char* rec = (unsigned char*)data_ov031_02290c94 + data_ov031_02290c94->field29;
				rec[8] = (unsigned char)v;
			}
			data_ov031_02290c94->field29 += 1;
			_Z20SetField123_02223fb4i(1);
			if (data_ov031_02290c94->field29 == 0x20) {
				_Z20SetField124_02223fc8i(0);
			}
		}
		break;
	}
epilogueA:
	func_ov031_0222d2bc();
	func_ov031_0222d3b0();
}
