#include <globaldefs.h>

void SetField54IfTagNot9Or10_ov031_022393e4(int v);
extern "C" void func_ov031_0223a374(void);
int SetupSlot13AndSetField54_02239ad8(void);
extern "C" void func_ov031_02239368(int val);

// USA: func_ov031_02239aa4  (semantic: CheckTagThenSetField54OrRunTen_02239aa4)
extern "C" ARM void func_ov031_02239aa4(unsigned short* a) {
	unsigned short v = a[1];
	if (v != 0) {
		SetField54IfTagNot9Or10_ov031_022393e4(v);
		func_ov031_0223a374();
		return;
	}
	if (SetupSlot13AndSetField54_02239ad8() != 0) return;
	func_ov031_02239368(9);
}
