#include <globaldefs.h>

extern "C" void* func_ov027_021db524(void);
void* SetBattleContextField0xc8IfIdle_020d472c(void* p);
extern "C" void func_ov027_021dd0cc(int a, int b);
int IssueBattleCommandSlot29_020d6ad4(int a, int b, int c, int d, unsigned short e);

struct CmdData021db490 {
	unsigned short f0;
	unsigned short f2;
	unsigned short f4;
	unsigned short f6;
};

extern CmdData021db490 data_ov027_021dd8ec;

// USA: func_ov027_021db490
ARM void IssueIdleBattleCommand_021db490(void) {
	void* r = SetBattleContextField0xc8IfIdle_020d472c((void*)func_ov027_021db524);
	func_ov027_021dd0cc(0x80, (int)r);
	int result = IssueBattleCommandSlot29_020d6ad4((int)func_ov027_021db524, data_ov027_021dd8ec.f6, data_ov027_021dd8ec.f2, data_ov027_021dd8ec.f0, data_ov027_021dd8ec.f4);
	func_ov027_021dd0cc(0x1d, result);
}
