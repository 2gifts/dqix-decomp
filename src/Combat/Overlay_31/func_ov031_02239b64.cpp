#include <globaldefs.h>

extern "C" void func_ov031_02239368(int val);
void SetField54IfTagNot9Or10_ov031_022393e4(int v);

// USA: func_ov031_02239b64  (semantic: CheckTagThenSetField9OrOne_02239b64)
extern "C" ARM void func_ov031_02239b64(unsigned short* a) {
	if (a[1] != 0) {
		func_ov031_02239368(9);
		SetField54IfTagNot9Or10_ov031_022393e4(a[1]);
		return;
	}
	func_ov031_02239368(1);
}
