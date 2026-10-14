#include <globaldefs.h>

ARM int CopyToBattleContextBuffer_020d4848(void* src);
ARM int IssueBattleCommandSlot1_020d5004(int arg);
ARM int IssueBattleCommandSlot2_020d503c(int arg);
ARM int TailCallForward_0223e2e0(int arg0, void* arg1);
extern "C" ARM unsigned int func_ov031_0223cf70(void** a);
extern "C" void func_ov031_022376fc(void);

extern char* data_ov031_02290d0c;

// USA: func_ov031_02237600
extern "C" ARM int func_ov031_02237600(void) {
	*(unsigned char*)(data_ov031_02290d0c + 0x1b94) = 1;
	CopyToBattleContextBuffer_020d4848(data_ov031_02290d0c + 0x13b8);

	if (*(unsigned short*)(data_ov031_02290d0c + 0x13b8) != 2) {
		int r = IssueBattleCommandSlot1_020d5004((int)func_ov031_022376fc);
		if (r != 2) {
			return 0;
		}
		do {
			CopyToBattleContextBuffer_020d4848(data_ov031_02290d0c + 0x13b8);
		} while (*(unsigned short*)(data_ov031_02290d0c + 0x13b8) != 2);
	}

	int r2 = IssueBattleCommandSlot2_020d503c((int)func_ov031_022376fc);
	if (r2 != 2) {
		return 0;
	}

	int field = *(unsigned int*)(data_ov031_02290d0c + 0x1b90);
	if (field != 0) {
		TailCallForward_0223e2e0(0, (void*)field);
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
