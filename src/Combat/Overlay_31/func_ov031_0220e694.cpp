#include <globaldefs.h>

extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220db6c(void);
extern "C" void func_ov031_0220d984(int, int, int, int);
extern int IssueBattleCommandSlot13_020d559c(int, unsigned int);
extern void* data_ov031_0224e53c;

struct TypeStruct_0220e694 { short f0; unsigned short type; };
struct TypeStruct_0220e4bc;
extern "C" void func_ov031_0220e4bc(struct TypeStruct_0220e4bc *s);

// USA: func_ov031_0220e694
extern "C" ARM void func_ov031_0220e694(struct TypeStruct_0220e694 *s) {
	switch (s->type) {
	case 0: {
		int f260 = *(int*)((char*)data_ov031_0224e53c + 0x2000 + 0x260);
		if (f260 == 0xc) {
			func_ov031_0220da1c(0xa);
			func_ov031_0220db6c();
			return;
		}
		int r = IssueBattleCommandSlot13_020d559c((int)func_ov031_0220e4bc, 0);
		if (r == 2) return;
		if (r == 3) goto case0_r3;
		if (r != 8) goto case0_r740;
		func_ov031_0220da1c(0xc);
		func_ov031_0220d984(1, (int)((char*)data_ov031_0224e53c + 0x2140), 0, 0x8b4);
		return;
	case0_r3:
		func_ov031_0220da1c(0xa);
		func_ov031_0220db6c();
		return;
	case0_r740:
		func_ov031_0220da1c(0xb);
		func_ov031_0220d984(7, (int)((char*)data_ov031_0224e53c + 0x2140), 0, 0x8c0);
		return;
	}
	case 1:
	case 3:
		func_ov031_0220da1c(0xa);
		func_ov031_0220db6c();
		return;
	case 2:
	case 4:
	default:
		func_ov031_0220da1c(0xb);
		func_ov031_0220d984(7, (int)((char*)data_ov031_0224e53c + 0x2140), 0, 0x8d3);
		return;
	}
}
