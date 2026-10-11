#include <globaldefs.h>

struct Layer0222fc48 {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
	unsigned char field6;
	unsigned char field7;
};

struct Ctx0222fc48 {
	unsigned char pad0[8];
	struct Layer0222fc48* field8;
};

extern struct Ctx0222fc48 data_ov031_02290ca0;

extern "C" char* _Z21GetOffset400_02235c70v(void);
extern "C" int func_ov031_0222fd9c(int idx);
extern "C" void func_ov031_0222fe30(int a, int b, int c);

// USA: func_ov031_0222fc48
extern "C" ARM void func_ov031_0222fc48(int idx, int arg) {
	unsigned char* obj = (unsigned char*)_Z21GetOffset400_02235c70v();
	int mode;
	int flag;

	switch (idx) {
	case 0:
	case 1:
		mode = 0;
		flag = mode;
		if (func_ov031_0222fd9c(mode) == 0) flag = 2;
		break;
	case 2: {
		int second = 0;
		int code;
		flag = second;
		if (obj[0xf5] != 0) {
			mode = 1;
			code = 4;
		} else {
			mode = 2;
			code = 3;
		}
		struct Layer0222fc48* layer = data_ov031_02290ca0.field8;
		if (layer->field4 != 0) flag = 1;
		if (layer->field5 != 0) second = 1;
		func_ov031_0222fe30(code, second, arg);
		break;
	}
	case 3:
	case 4:
	case 5:
		mode = 0;
		flag = obj[0xf5] != 0 ? 2 : mode;
		break;
	case 6: {
		int first;
		int second = 0;
		flag = second;
		if (obj[0xf6] != 0) {
			mode = 1;
			first = 4;
		} else {
			if (obj[0xf5] == 0) flag = 2;
			mode = 2;
			first = 3;
		}
		struct Layer0222fc48* layer = data_ov031_02290ca0.field8;
		if (layer->field6 != 0) flag = 1;
		if (layer->field7 != 0) second = 1;
		func_ov031_0222fe30(first, second, arg);
		break;
	}
	case 7:
	case 8:
		mode = 0;
		flag = obj[0xf6] != 0 ? 2 : mode;
		break;
	default:
		mode = 0;
		flag = 2;
		break;
	}

	func_ov031_0222fe30(mode, flag, arg);
}
