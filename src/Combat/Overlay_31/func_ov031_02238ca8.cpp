// JPN: func_ov031_02239488
#include <globaldefs.h>
#include "System/Interrupts.h"

void SetGlobal02290d14_02239108(unsigned short v);
#if defined(jpn)
extern "C" void func_ov027_021dcd5c(void* obj);
#else
void ResetBlockFields_021dcd5c(void* obj);
#endif
extern "C" int func_ov027_021d8b40(int index, int flag);
extern unsigned short* data_ov031_02290d14;

// USA: func_ov031_02238ca8
extern "C" ARM void func_ov031_02238ca8(void) {
	unsigned short index = 1;
	unsigned short accumFlag = 0;
	do {
		if (data_ov031_02290d14[5] & (1 << index)) {
			if (func_ov027_021d8b40(index, 3) != 0) {
				accumFlag |= (1 << index);
			} else {
				unsigned short mask = (unsigned short)~(1 << index);
				int oldIRQ = DisableIRQInterrupts();
				data_ov031_02290d14[1] &= mask;
				data_ov031_02290d14[2] &= mask;
				data_ov031_02290d14[3] &= mask;
				data_ov031_02290d14[4] &= mask;
				data_ov031_02290d14[5] &= mask;
				data_ov031_02290d14[6] &= mask;
				SetIRQInterruptState(oldIRQ);
#if defined(jpn)
				func_ov027_021dcd5c((void*)index);
#else
				ResetBlockFields_021dcd5c((void*)index);
#endif
			}
		}
		index++;
	} while (index < 0x10);

	if (accumFlag == 0) {
		SetGlobal02290d14_02239108(7);
	} else {
		SetGlobal02290d14_02239108(4);
	}
}
