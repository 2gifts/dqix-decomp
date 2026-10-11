// JPN: func_ov031_02244500
#include <globaldefs.h>
#include "System/Timing.h"

struct Struct_02245528;

ARM void CallWithConsts3_1_14_02211c38(int a);
ARM void SetDataFromIndex_02211c50(int idx);
extern "C" void func_ov031_02211ca0(void);
extern "C" void func_ov031_02211e08(void);
extern "C" int func_ov031_02211db0(void);
extern "C" int func_ov031_02211f24(void);
extern "C" void _Z32SetField34AndClear35_37_02245528P15Struct_02245528i(struct Struct_02245528* p, int v);
extern "C" void func_ov031_022120f8(void);
extern "C" void func_ov031_02245478(void);

struct S02243d20 {
	unsigned char pad0[0x35];
	unsigned char state35;
	unsigned char pad1[0x310 - 0x36];
	unsigned char field310[1];
	unsigned char pad2[0x384 - 0x311];
	int field384;
	unsigned char pad3[0x3a8 - 0x388];
	unsigned int field3a8;
	unsigned int field3ac;
};

// USA: func_ov031_02243d20
extern "C" ARM void func_ov031_02243d20(S02243d20* obj) {
	switch (obj->state35) {
	case 0:
		CallWithConsts3_1_14_02211c38((int)&obj->field310);
#if !defined(jpn)
		SetDataFromIndex_02211c50(2);
#endif
		func_ov031_02211ca0();
		{
			uint64_t t = GetCurrentTimestamp() + 0xefb5f7;
			obj->field3a8 = (unsigned int)t;
			obj->field3ac = (unsigned int)(t >> 32);
		}
		obj->state35 = 4;
		break;
	case 4:
		func_ov031_02211e08();
		if (func_ov031_02211db0() != 0) {
			obj->state35 = 5;
			if (obj->field384 < 0x3c000) obj->field384 = 0x3c000;
		} else {
			if (obj->field384 < 0x3c000) obj->field384 += 0x333;
		}
		break;
	case 5:
		{
			int v = func_ov031_02211f24();
			switch (v) {
			case 4:
				obj->state35 = 6;
				break;
			case 7:
			case 8:
				obj->state35 = 8;
				break;
			}
		}
		break;
	case 6:
		_Z32SetField34AndClear35_37_02245528P15Struct_02245528i((struct Struct_02245528*)obj, 3);
		break;
	case 7:
		func_ov031_022120f8();
		_Z32SetField34AndClear35_37_02245528P15Struct_02245528i((struct Struct_02245528*)obj, 0);
		break;
	case 8:
		func_ov031_02245478();
		func_ov031_022120f8();
		break;
	default:
		break;
	}
}
