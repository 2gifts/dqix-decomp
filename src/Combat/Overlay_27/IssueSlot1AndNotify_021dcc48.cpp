#include <globaldefs.h>

int IssueBattleCommandSlot1_020d5004(int arg);
extern "C" void func_ov027_021dd0cc(int a, int b);

struct FieldHolder_021dcc48 {
	unsigned char pad0[8];
	unsigned char* ptr;
};

extern FieldHolder_021dcc48 data_ov027_021e33e0;

// USA: func_ov027_021dcc48  (semantic: IssueSlot1AndNotify_021dcc48)
extern "C" ARM int func_ov027_021dcc48(void) {
	int result = IssueBattleCommandSlot1_020d5004(*(int*)(data_ov027_021e33e0.ptr + 0x508));
	func_ov027_021dd0cc(1, result);
	if (result == 2) result = 0;
	return result;
}
