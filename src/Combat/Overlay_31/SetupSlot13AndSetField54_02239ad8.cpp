#include <globaldefs.h>

extern "C" void func_ov031_02239368(int);
extern int IssueBattleCommandSlot13_020d559c(int, unsigned int);
extern "C" void func_ov031_02239b10(void);
extern void SetField54IfTagNot9Or10_ov031_022393e4(int);
extern int CheckFirstOrRunTen_0223a358(void);

// USA: func_ov031_02239ad8
ARM int SetupSlot13AndSetField54_02239ad8(void) {
	func_ov031_02239368(3);
	int r = IssueBattleCommandSlot13_020d559c((int)func_ov031_02239b10, 0);
	if (r == 2) return 1;
	SetField54IfTagNot9Or10_ov031_022393e4(r);
	CheckFirstOrRunTen_0223a358();
	return 0;
}
