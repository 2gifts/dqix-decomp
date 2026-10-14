#include <globaldefs.h>

struct St02235234 {
	unsigned char pad[0x14];
	unsigned short pos14;
	unsigned short pos16;
	unsigned char field18;
	unsigned char field19;
	unsigned char field1a;
	unsigned char field1b;
	unsigned char field1c;
	unsigned char field1d;
	unsigned char field1e;
};

extern St02235234* data_ov031_02290cf4;

extern "C" ARM int func_ov031_02235594(void);
extern "C" ARM void func_ov031_0223552c(void);
extern "C" ARM void func_ov031_022353b8(void);
extern "C" ARM int func_ov031_02235620(int);
extern "C" ARM int func_ov031_02236878(int);
extern "C" ARM void func_ov031_0223689c(unsigned char);
extern "C" ARM int func_ov031_0223d69c(void*);
void SetField1cAnd1d_02235500(int a);

// USA: func_ov031_02235234
extern "C" ARM void func_ov031_02235234(void) {
	data_ov031_02290cf4->field1d = 0;
	switch (data_ov031_02290cf4->field1c) {
	case 0:
		if (data_ov031_02290cf4->field1e != 0) {
			break;
		}
		switch (func_ov031_02235594()) {
		case 1:
			if (data_ov031_02290cf4->field1b != 0) {
				func_ov031_02236878(0x16);
				func_ov031_0223689c(0);
				data_ov031_02290cf4->field1d = 1;
				func_ov031_0223d69c(&data_ov031_02290cf4->pos14);
				data_ov031_02290cf4->field18 = data_ov031_02290cf4->field1a;
				data_ov031_02290cf4->field1c = 1;
			}
			break;
		case 2:
			SetField1cAnd1d_02235500(2);
			break;
		case 3:
			SetField1cAnd1d_02235500(3);
			break;
		case 4:
			func_ov031_0223552c();
			break;
		}
		break;
	case 1:
		func_ov031_022353b8();
		break;
	case 2:
		if (func_ov031_02235620(2) != 2) {
			data_ov031_02290cf4->field1d = 5;
			data_ov031_02290cf4->field1c = 0;
		} else if (func_ov031_02235594() == 2) {
			SetField1cAnd1d_02235500(2);
		}
		break;
	case 3:
		if (func_ov031_02235620(3) != 3) {
			data_ov031_02290cf4->field1d = 7;
			data_ov031_02290cf4->field1c = 0;
		} else if (func_ov031_02235594() == 3) {
			SetField1cAnd1d_02235500(3);
		}
		break;
	}
}
