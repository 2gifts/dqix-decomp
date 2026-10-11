#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" int func_ov027_021d8b40(int index, int flag);
#if defined(jpn)
extern "C" void func_ov027_021dcd5c(int index);
#else
void ResetBlockFields_021dcd5c(void* obj);
#endif

extern unsigned short* data_ov031_02290d14;

// JPN: func_ov031_022390f0
// USA: func_ov031_02238910  (semantic: MaskChannelBit_02238910)
extern "C" ARM void func_ov031_02238910(int index) {
	if (func_ov027_021d8b40(index, 1) != 0) return;
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
	func_ov027_021dcd5c(index);
#else
	ResetBlockFields_021dcd5c((void*)index);
#endif

}
