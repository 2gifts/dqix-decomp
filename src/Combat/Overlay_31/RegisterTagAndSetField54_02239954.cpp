#include <globaldefs.h>

extern "C" int func_ov031_02239368(int);
extern "C" void func_ov031_02239984(void);
int TrySetBattleContextField020d5aec(int a);
void SetField54IfTagNot9Or10_ov031_022393e4(int v);

// USA: func_ov031_02239954
ARM int RegisterTagAndSetField54_02239954(void) {
	func_ov031_02239368(3);
	int r = TrySetBattleContextField020d5aec((int)func_ov031_02239984);
	if (r == 2) {
		return 1;
	}
	SetField54IfTagNot9Or10_ov031_022393e4(r);
	return 0;
}
