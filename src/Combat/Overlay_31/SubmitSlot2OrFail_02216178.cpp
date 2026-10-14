#include <globaldefs.h>

extern void* data_ov031_0224e5d8;
int IssueBattleCommandSlot11_020d5490(int);

// USA: func_ov031_02216178  (semantic: SubmitSlot2OrFail_02216178)
extern "C" ARM int func_ov031_02216178(int arg) {
	if (arg == 0) return -1;
	*(int*)((char*)data_ov031_0224e5d8 + 0x1000 + 0xa90) = 2;
	int r = IssueBattleCommandSlot11_020d5490(arg);
	return (r == 2) ? 0 : r;
}
