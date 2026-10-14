#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct FourWords {
	int field0;
	int field4;
	int field8;
	int fieldc;
};

struct Mutex;
void ZeroInitializeMutex(Mutex*);
bool IsContextInactive(ProcessorContext* context);
extern "C" void func_ov031_02218098(void);

extern int data_ov031_0224e608;

// USA: func_ov031_02217db4  (semantic: InitOrResumeContext_02217db4)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02217db4(void* s, unsigned int stackSize) {
	*(int*)((char*)s + 0x1c10) = 0;
	ZeroInitializeMutex((Mutex*)((char*)s + 0x1bf8));
	ZeroInitializeMutex((Mutex*)((char*)s + 0x1a18));
	if (*(int*)((char*)s + 0x1018) == 1) {
		data_ov031_0224e608 = 1;
	} else {
		data_ov031_0224e608 = 0;
	}
	if (*(int*)((char*)s + 0x1ba4) != 0) {
		if (!IsContextInactive((ProcessorContext*)((char*)s + 0x1b38))) {
			return;
		}
	}
	PopulateContext((ProcessorContext*)((char*)s + 0x1b38), (unsigned int)func_ov031_02218098, (unsigned int)s, (unsigned int)((char*)s + 0x1000), 0x1000, stackSize);
	MarkContextReadyAndSwitch((ProcessorContext*)((char*)((int)s + 0x338) + 0x1800));
}
