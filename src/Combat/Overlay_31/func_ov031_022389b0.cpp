// JPN: func_ov031_02239190
#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" int func_ov027_021d8b40(int index, int flag);
#if defined(jpn)
extern "C" void func_ov027_021dcd5c(void* obj);
#else
void ResetBlockFields_021dcd5c(void* obj);
#endif
extern unsigned short* data_ov031_02290d14;

// USA: func_ov031_022389b0  (semantic: MaskChannelBitOrClearTwo_022389b0)
extern "C" ARM void func_ov031_022389b0(int index) {
	if (func_ov027_021d8b40(index, 0) == 0) {
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
	} else {
		int oldIRQ = DisableIRQInterrupts();
		int mask = ~(1 << index);
		data_ov031_02290d14[2] &= mask;
		data_ov031_02290d14[1] &= mask;
		SetIRQInterruptState(oldIRQ);
	}
}
