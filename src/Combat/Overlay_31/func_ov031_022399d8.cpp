#include <globaldefs.h>

int IssueBattleCommandSlot9_020d5214(int arg);
void SetField54IfTagNot9Or10_ov031_022393e4(int v);
int SetField54OrTagOne_02239a00(short* p);

// USA: func_ov031_022399d8
extern "C" ARM int func_ov031_022399d8(void) {
	int r = IssueBattleCommandSlot9_020d5214((int)SetField54OrTagOne_02239a00);
	if (r == 2) return 1;
	SetField54IfTagNot9Or10_ov031_022393e4(r);
	return 0;
}
