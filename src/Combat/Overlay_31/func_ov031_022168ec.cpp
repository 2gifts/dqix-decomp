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
extern "C" void func_ov031_02216ca0(void);

struct Glob0224e5e8_022168ec { char pad[8]; char* base; };
extern Glob0224e5e8_022168ec data_ov031_0224e5e8;
extern int data_ov031_0224e5f0;

// USA: func_ov031_022168ec
#pragma optimize_for_size off
extern "C" ARM void func_ov031_022168ec(void) {
	ZeroInitializeMutex((Mutex*)(data_ov031_0224e5e8.base + 0x13d8));

	*(int*)(data_ov031_0224e5e8.base + 0x13f0) = 0;

	if (*(int*)(data_ov031_0224e5e8.base + 0x1384) != 0) {
		if (!IsContextInactive((ProcessorContext*)(data_ov031_0224e5e8.base + 0x1318))) {
			return;
		}
	}

	PopulateContext((ProcessorContext*)(data_ov031_0224e5e8.base + 0x1318), (unsigned int)func_ov031_02216ca0,
		(unsigned int)&data_ov031_0224e5f0, (unsigned int)(data_ov031_0224e5e8.base + 0x1000), 0x1000, 0x10);
	MarkContextReadyAndSwitch((ProcessorContext*)(data_ov031_0224e5e8.base + 0x1318));
}
