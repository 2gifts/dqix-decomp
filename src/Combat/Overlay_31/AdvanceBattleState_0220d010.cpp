#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"

int IssueBattleCommandSlot29_020d6ad4(int arg, int a, int b, int c, unsigned short d);
extern "C" void func_ov031_0220da1c(int);
extern "C" int func_ov031_0220d570(int);
extern "C" void func_ov031_0220dc40(void);
extern int data_ov031_0224e53c;

// USA: func_ov031_0220d010  (semantic: AdvanceBattleState_0220d010)
extern "C" ARM int func_ov031_0220d010(void* a0, unsigned char* a1, int a2) {
	int state = DisableIRQInterrupts();
	if (data_ov031_0224e53c == 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	int v = *(int*)((char*)data_ov031_0224e53c + 0x2260);
	switch (v) {
	case 3: {
		if (a0 == 0) {
			SetIRQInterruptState(state);
			return 1;
		}
		if (*(unsigned short*)((char*)a0 + 0x3c) != 0) {
			SetIRQInterruptState(state);
			return 1;
		}
		if (a1 != 0) {
			if (!(a1[0] < 4 && a1[1] < 4)) {
				SetIRQInterruptState(state);
				return 1;
			}
			*(unsigned char*)((char*)data_ov031_0224e53c + 0x2250) = a1[0];
			*(unsigned char*)((char*)data_ov031_0224e53c + 0x2251) = a1[1];
			if (*(unsigned char*)((char*)data_ov031_0224e53c + 0x2250) == 0) {
				VectorizedMemset((char*)data_ov031_0224e53c + 0x2200, 0, 0x50);
			} else {
				VectorizedInvertedMemcpy(a1 + 2, (char*)data_ov031_0224e53c + 0x2200, 0x50);
			}
		} else {
			VectorizedMemset((char*)data_ov031_0224e53c + 0x2200, 0, 0x52);
		}

		VectorizedInvertedMemcpy(a0, (char*)data_ov031_0224e53c + 0x2140, 0xc0);
		*(unsigned short*)((char*)data_ov031_0224e53c + 0x2170) = *(unsigned short*)((char*)data_ov031_0224e53c + 0x216e) | 3;
		func_ov031_0220d570(a2);
		break;
	}
	case 8:
		SetIRQInterruptState(state);
		return 2;
	case 9:
		SetIRQInterruptState(state);
		return 0;
	default:
		SetIRQInterruptState(state);
		return 1;
	}

	int r = IssueBattleCommandSlot29_020d6ad4((int)func_ov031_0220dc40, 0xffff, 0x50, 0xffff, 0xffff);
	switch (r) {
	case 2:
		func_ov031_0220da1c(8);
		*(unsigned short*)((char*)data_ov031_0224e53c + 0x2280) = 5;
		goto ret3;
	case 8:
		SetIRQInterruptState(state);
		return 4;
	case 3:
	default:
		func_ov031_0220da1c(0xb);
		SetIRQInterruptState(state);
		return 7;
	}
ret3:
	SetIRQInterruptState(state);
	return 3;
}
