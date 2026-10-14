#include <globaldefs.h>

extern "C" void func_ov031_02239368(int val);
ARM void SetField54IfTagNot9Or10_ov031_022393e4(int v);
ARM int BuildAndDispatch020d5898(int a, int b, int c, int d, unsigned short e, unsigned short f);
extern "C" void func_ov031_022397bc(void);

struct Inner02290d18 { unsigned char pad[0x40]; int field40; };
struct Outer02290d18 { unsigned char pad[4]; Inner02290d18* field4; };
extern Outer02290d18 data_ov031_02290d18;

// USA: func_ov031_02239724  (semantic: CheckTagOrDispatchAndSetField54_02239724)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02239724(void) {
	if ((unsigned int)(data_ov031_02290d18.field4->field40 - 4) <= 2) {
		return 1;
	}
	func_ov031_02239368(4);
	char* base = (char*)data_ov031_02290d18.field4;
	int e = *(int*)(base + 0x1000 + 0x2a0);
	int c = (unsigned short)*(int*)(base + 0x1000 + 0x2a4);
	int r = BuildAndDispatch020d5898((int)func_ov031_022397bc, (int)(base + 0x1060), c, (int)(base + 0xf80), (unsigned short)e, 1);
	if (r == 2) {
		return 1;
	}
	SetField54IfTagNot9Or10_ov031_022393e4(r);
	return 0;
}
