// JPN: func_ov031_02237de0
#include <globaldefs.h>

ARM int CopyToBattleContextBuffer(void* src);
ARM int IssueBattleCommandSlot1(int arg);
ARM int IssueBattleCommandSlot2(int arg);
extern "C" ARM int _Z24TailCallForward_0223e2e0iPv(int arg0, void* arg1);
extern "C" ARM unsigned int func_ov031_0223cf70(void** a);
extern "C" void func_ov031_022376fc(void);

extern char* data_ov031_02290d0c;

// USA: func_ov031_02237600
extern "C" ARM int func_ov031_02237600(void) {
	*(unsigned char*)(data_ov031_02290d0c + 0x1b94) = 1;
	CopyToBattleContextBuffer(data_ov031_02290d0c + 0x13b8);

	if (*(unsigned short*)(data_ov031_02290d0c + 0x13b8) != 2) {
		int r = IssueBattleCommandSlot1((int)func_ov031_022376fc);
		if (r != 2) {
			return 0;
		}
		do {
			CopyToBattleContextBuffer(data_ov031_02290d0c + 0x13b8);
		} while (*(unsigned short*)(data_ov031_02290d0c + 0x13b8) != 2);
	}

	int r2 = IssueBattleCommandSlot2((int)func_ov031_022376fc);
	if (r2 != 2) {
		return 0;
	}

	int field = *(unsigned int*)(data_ov031_02290d0c + 0x1b90);
	if (field != 0) {
		_Z24TailCallForward_0223e2e0iPv(0, (void*)field);
	}

	while (*(volatile unsigned char*)(data_ov031_02290d0c + 0x1b94) != 2) {
	}

	{
		extern char* data_ov031_02290d0c;
#if defined(jpn)
		func_ov031_0223cf70((void**)0x0229190C);
#else
		func_ov031_0223cf70((void**)0x02290D0C);
#endif
	}
	return 1;
}
