#include <globaldefs.h>

int IssueBattleCommandSlot30_020d6b34(int a0, short a1, short a2, short a3, unsigned short a4);

// USA: func_ov031_02239e48
ARM int IssueSlotCommand3_17_02239e48(int a0, short a1) {
	return IssueBattleCommandSlot30_020d6b34(a0, 3, 0x11, a1, 0x1e);
}
