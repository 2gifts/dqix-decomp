#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
void SetIRQInterruptState(int mask);
void InvalidateDataCacheRange(const void* addr, unsigned int size);
int ClearBattleSaveContext020d3fdc(void);
int SubmitBattleContextSlot4_020d4ebc(int value);
int IssueBattleCommandSlot6_020d4f3c(int fn);
int IssueBattleCommandSlot1_020d5004(int fn);
unsigned short* GetBattleField4IfActive_020d46a8(void);
extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220dc40(void);
extern "C" void func_ov031_0220e7b0(void);

struct StructE53C_0220d330 {
	char pad[0x2260];
	int state;
	char pad2[0x226b - 0x2264];
	unsigned char flag226b;
	char pad3[0x2280 - 0x226c];
	short field2280;
};

extern StructE53C_0220d330* data_ov031_0224e53c;

// USA: func_ov031_0220d330  (semantic: DispatchBattleAlarmState_0220d330)
extern "C" ARM int func_ov031_0220d330(void) {
	int mask = DisableIRQInterrupts();
	if (data_ov031_0224e53c == 0) {
		SetIRQInterruptState(mask);
		return 1;
	}

	int result;
	switch (data_ov031_0224e53c->state) {
		case 13:
			SetIRQInterruptState(mask);
			return 2;
		case 1:
			SetIRQInterruptState(mask);
			return 0;
		case 6:
			func_ov031_0220da1c(0xd);
			data_ov031_0224e53c->field2280 = 9;
			SetIRQInterruptState(mask);
			return 3;
		case 0:
		case 2:
		case 4:
		case 5:
		case 7:
		case 8:
		case 10:
		case 11:
		default:
			SetIRQInterruptState(mask);
			return 1;
		case 3:
		case 9:
		case 12:
			if (data_ov031_0224e53c->flag226b == 1) {
				func_ov031_0220da1c(0xd);
				data_ov031_0224e53c->field2280 = 9;
				goto epilogue3;
			}
			{
				unsigned short* field4 = GetBattleField4IfActive_020d46a8();
				InvalidateDataCacheRange(field4, 2);
				switch (*field4) {
					case 0:
						result = ClearBattleSaveContext020d3fdc();
						if (result != 0) break;
						func_ov031_0220da1c(1);
						data_ov031_0224e53c->field2280 = 0;
						SetIRQInterruptState(mask);
						return 0;
					case 1:
						result = SubmitBattleContextSlot4_020d4ebc((int)func_ov031_0220dc40);
						break;
					case 2:
						result = IssueBattleCommandSlot6_020d4f3c((int)func_ov031_0220dc40);
						break;
					default:
						data_ov031_0224e53c->flag226b = 1;
						result = IssueBattleCommandSlot1_020d5004((int)func_ov031_0220e7b0);
						break;
				}
			}
			break;
	}

	switch (result) {
		case 2:
			func_ov031_0220da1c(0xd);
			data_ov031_0224e53c->field2280 = 9;
			goto epilogue3;
		case 8:
			SetIRQInterruptState(mask);
			return 4;
		case 3:
		default:
			func_ov031_0220da1c(0xb);
			SetIRQInterruptState(mask);
			return 7;
	}

epilogue3:
	SetIRQInterruptState(mask);
	return 3;
}
