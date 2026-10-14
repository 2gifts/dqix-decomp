#include <globaldefs.h>

struct RootStruct021dcd5c {
	unsigned char pad[0xc];
	unsigned char *fieldc;
};

extern RootStruct021dcd5c data_ov027_021e33e0;

int IssueBattleCommandSlot13_020d559c(int a0, unsigned int a1);
extern "C" void func_ov027_021db524(void);
extern "C" void VectorizedMemset(void *dst, int val, int size);
void ClearEntrySlot_021dd5f4(int index);

// USA: func_ov027_021dcd5c  (semantic: IssueCommandAndClearSlotFields_021dcd5c)
extern "C" ARM void func_ov027_021dcd5c(int index) {
	int idx;

	IssueBattleCommandSlot13_020d559c((int)func_ov027_021db524, index);
	if (index == 0 || (unsigned int)index >= 0x10) {
		return;
	}

	idx = index - 1;

	*(unsigned short *)(data_ov027_021e33e0.fieldc + 0x1400 + (idx << 1) + 0x8a) = 0;

	VectorizedMemset(data_ov027_021e33e0.fieldc + 0x1400 + 0xa8 + (idx << 2), 0, 4);

	VectorizedMemset(data_ov027_021e33e0.fieldc + 0x1340 + idx * 0x16, 0, 0x16);

	ClearEntrySlot_021dd5f4(index);

	*(unsigned short *)(data_ov027_021e33e0.fieldc + 0x1700 + (idx << 1) + 0x54) = 0;

	{
		signed char v = *(signed char *)(data_ov027_021e33e0.fieldc + 0x1500 + idx + 0x26);
		if (v != -1) {
			int mask = ~(1 << index);
			int off = (unsigned char)v * 0x5d4;

			*(unsigned short *)(data_ov027_021e33e0.fieldc + off + 0x1d00 + 0x4e) &= mask;
			*(unsigned short *)(data_ov027_021e33e0.fieldc + off + 0x1d00 + 0x50) |= (1 << index);
			*(signed char *)(data_ov027_021e33e0.fieldc + 0x1000 + (index - 1) + 0x526) = -1;
			*(unsigned short *)(data_ov027_021e33e0.fieldc + off + 0x1d00 + 0x4c) &= mask;
		}
	}

	if (*(unsigned short *)(data_ov027_021e33e0.fieldc + 0x1500 + 0x36) & (1 << index)) {
		(*(unsigned char *)(data_ov027_021e33e0.fieldc + 0x1000 + 0x535))--;
		*(unsigned short *)(data_ov027_021e33e0.fieldc + 0x1500 + 0x36) &= ~(1 << index);
	}

	*(int *)(data_ov027_021e33e0.fieldc + 0x1000 + (idx << 2) + 0x4e8) = 0;
}
